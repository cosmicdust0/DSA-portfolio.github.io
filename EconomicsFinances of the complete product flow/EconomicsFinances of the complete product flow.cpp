#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <bits/stdc++.h>

class Ingredient {
public:
  std::string name;
  double cost_per_unit;
  std::string unit;
  double quantity_per_bottle;

  // Constructor and other member functions (if needed)
  Ingredient(const std::string& name, double cost, const std::string& unit, double quantity) :
      name(name), cost_per_unit(cost), unit(unit), quantity_per_bottle(quantity) {}
};

struct CategoryNode {
  std::string name;
  std::vector<std::unique_ptr<CategoryNode>> children;  // Use smart pointers for memory management
  std::unordered_set<std::string> ingredients;  // Set of ingredient names in this category
};

// Global variable for the root node of the category tree
std::unique_ptr<CategoryNode> root = nullptr;

// Function to add a new category to the tree
void addCategory(const std::string& category_name, CategoryNode* parent = nullptr) {
  std::unique_ptr<CategoryNode> new_node(new CategoryNode);  // Use smart pointer
  new_node->name = category_name;

  if (parent == nullptr) {
    if (root == nullptr) {
      root = std::move(new_node);  // Move ownership to root
    } else {
      root->children.push_back(std::move(new_node));  // Move ownership to child list
    }
  } else {
    parent->children.push_back(std::move(new_node));  // Move ownership to child list
  }
}

// Function to find a category node by name (recursive)
CategoryNode* findCategoryNode(const std::string& name, CategoryNode* node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->name == name) {
    return node;
  }
  for (auto& child : node->children) {
    CategoryNode* found_node = findCategoryNode(name, child.get());
    if (found_node != nullptr) {
      return found_node;
    }
  }
  return nullptr;
}

// Ingredient map for quick name-based retrieval
std::unordered_map<std::string, Ingredient> ingredients_map;

// Function to add an ingredient with category assignment
void addIngredient(const Ingredient& ingredient, const std::string& category_name) {
  ingredients_map[ingredient.name] = ingredient;
  // Find the category node
  CategoryNode* target_node = findCategoryNode(category_name, root.get());
  if (target_node != nullptr) {
    target_node->ingredients.insert(ingredient.name);
  }
}

// Function to get ingredients by name
Ingredient getIngredientByName(const std::string& name) {
  if (ingredients_map.count(name) > 0) {
    return ingredients_map[name];
  } else {
    throw std::runtime_error("Ingredient not found!");
  }
}

// Function to get ingredients by category (recursive approach)
std::vector<Ingredient> getIngredientsByCategory(const std::string& category_name) {
  std::vector<Ingredient> ingredients;
  // Find the category node
  CategoryNode* target_node = findCategoryNode(category_name, root.get());
  if (target_node != nullptr) {
    // Add ingredients from the category set and its children (recursive)
    for (const std::string& ingredient_name : target_node->ingredients) {
      ingredients.push_back(ingredients_map[ingredient_name]);
    }
    for (const auto& child : target_node->children) {
      std::vector<Ingredient> child_ingredients = getIngredientsByCategory(child->name);
      ingredients.insert(ingredients.end(), child_ingredients.begin(), child_ingredients.end());
    }
  }
  return ingredients;
}

  
// hash map  implementation for production costs


// ProductionCost struct
struct ProductionCost {
  double cost_per_unit;
  std::string description;
};

// In-memory hash map for production costs
std::unordered_map<int, ProductionCost> in_memory_costs;
int next_cost_id = 1;  // Track the next available ID for new costs

// Function to add a new production cost
void addProductionCost(const ProductionCost& cost) {
  in_memory_costs[next_cost_id] = cost;
  next_cost_id++;
}

// Function to get a production cost by ID (if found in memory)
ProductionCost getProductionCost(int id) {
  if (in_memory_costs.count(id) > 0) {
    return in_memory_costs[id];
  } else {
    // Handle cost not found (e.g., return an empty cost or throw an exception)
    ProductionCost empty_cost;
    return empty_cost;
  }
}

// (Optional) Function to update a production cost in memory (if found)
void updateProductionCost(int id, const ProductionCost& updated_cost) {
  if (in_memory_costs.count(id) > 0) {
    in_memory_costs[id] = updated_cost;
  } else {
    // Handle cost not found (similar to getProductionCost)
  }
}

// (Optional) Function to remove a production cost from memory (if found)
void removeProductionCost(int id) {
  if (in_memory_costs.count(id) > 0) {
    in_memory_costs.erase(id);
  } else {
    // Handle cost not found
  }
}
#include <vector>
#include <string>
#include <limits>

struct MarketingChannel {
  std::string name;
  double cost_per_reach;
  double minimum_reach;
  std::vector<std::string> target_audiences;  // Optional: Target audience suitability
  double total_cost;  // Calculated and stored within the MarketingChannel object
};

class MarketingChannelHeap {
private:
  std::vector<MarketingChannel> channels;

  bool compareChannels(const MarketingChannel& a, const MarketingChannel& b) {
    return (a.total_cost > b.total_cost);  // Min-heap for lowest total cost
  }

public:
  void addChannel(const MarketingChannel& channel, int desired_reach) {
    double total_cost = (desired_reach < channel.minimum_reach) ?
        channel.cost_per_reach * channel.minimum_reach :
        channel.cost_per_reach * (desired_reach / channel.minimum_reach);
    channel.total_cost = total_cost;
    channels.push_back(channel);
    siftUp(channels.size() - 1);
  }

  MarketingChannel extractCheapest() {
    if (channels.empty()) {
      throw std::runtime_error("Heap is empty!");
    }
    MarketingChannel cheapest = channels[0];
    channels[0] = channels.back();
    channels.pop_back();
    siftDown(0);
    return cheapest;
  }

private:
  void siftUp(int index) {
    while (index > 0 && compareChannels(channels[index], channels[(index - 1) / 2])) {
      std::swap(channels[index], channels[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void siftDown(int index) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int smallest_index = index;

    if (left_child_index < channels.size() && compareChannels(channels[left_child_index], channels[smallest_index])) {
      smallest_index = left_child_index;
    }
    if (right_child_index < channels.size() && compareChannels(channels[right_child_index], channels[smallest_index])) {
      smallest_index = right_child_index;
    }

    if (smallest_index != index) {
      std::swap(channels[index], channels[smallest_index]);
      siftDown(smallest_index);
    }
  }
};



int main() {

  addCategory("Fruits");
  addCategory("Citrus", findCategoryNode("Fruits", root.get()));  // Add as child of Fruits
  addCategory("Spices");

  
  // Example usage
  ProductionCost cost1{1.50, "Machinery operation"};
  addProductionCost(cost1);

  ProductionCost cost2{2.00, "Labor cost"};
  addProductionCost(cost2);

  ProductionCost retrieved_cost = getProductionCost(1);
  // Use retrieved_cost information

  // (Optional) Update or remove costs using the provided functions
  MarketingChannel channel1{"Billboard", 0.10, 10000, {"Young Adults"}};
  MarketingChannel channel2{"TV Ad", 0.05, 500000, {}};  // Reaches all audiences
  MarketingChannel channel3{"Radio Spot", 0.02, 20000, {"Adults"}};

  MarketingChannelHeap channel_heap;
  channel_heap.addChannel(channel1, 25000);  // Calculate total cost based on desired reach
  channel_heap.addChannel(channel2, 1000000);
  channel_heap.addChannel(channel3, 30000);

  std::string target_audience = "Young Adults";
  int desired_reach = 50000;

  MarketingChannel cheapest_option = channel_heap.extractCheapest();
  if (cheapest_option.name.empty()) {
    std::cout << "No suitable channel found for the target audience." << std::endl;
  } else {
    std::cout << "Cheapest option for " << target_audience << " with reach " << desired_reach << ":" << std::endl;
    std::cout << "  - Channel: " << cheapest_option.name << std::endl;
    std::cout << "  - Total Cost: $" << cheapest_option.total_cost << std::endl;
  }

  return 0;
}
