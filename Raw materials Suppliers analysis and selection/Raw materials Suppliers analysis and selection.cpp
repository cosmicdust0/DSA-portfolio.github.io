#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

struct InventoryItem {
    string name;
    int quantity;
    string dateOfManufacture;
    int shelfLife; 
    string conditionToStoreIn;
};

string getCurrentDateAsString() {
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    return ctime(&time);
}

class InventoryManager {
private:
    unordered_map<string, InventoryItem> inventory;

public:
    void addItem(string name, int quantity, string dateOfManufacture, int shelfLife, string conditionToStoreIn) {
        inventory[name] = {name, quantity, dateOfManufacture, shelfLife, conditionToStoreIn};
    }

    void removeItem(string name) {
        if (inventory.find(name) != inventory.end()) {
            inventory.erase(name);
        } else {
            cout << "Item not found in inventory." << endl;
        }
    }

    void updateQuantity(string name, int quantity) {
        if (inventory.find(name) != inventory.end()) {
            inventory[name].quantity = quantity;
        } else {
            cout << "Item not found in inventory." << endl;
        }
    }

    void displayInventory() {
        cout << "Inventory:\n";
        for (const auto& item : inventory) {
            cout << "Name: " << item.second.name << ", Quantity: " << item.second.quantity << ", Manufacture Date: " << item.second.dateOfManufacture
                 << ", Shelf Life: " << item.second.shelfLife << " days, Condition to Store In: " << item.second.conditionToStoreIn << endl;
        }
    }
};

int main() {
    InventoryManager manager;

    manager.addItem("item1", 10, getCurrentDateAsString(), 30, "Dry place");
    manager.addItem("item2", 20, getCurrentDateAsString(), 60, "Cool place");
    manager.addItem("item3", 15, getCurrentDateAsString(), 45, "Dark place");

    manager.updateQuantity("item2", 25);

    manager.displayInventory();

    return 0;
}
