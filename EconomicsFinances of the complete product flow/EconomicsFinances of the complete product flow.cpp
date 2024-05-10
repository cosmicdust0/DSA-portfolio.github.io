#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// Struct to represent supplier details including cost of goods and additional fields
struct Supplier {
    string name;
    float costOfGoods;
    string location;
    string contactPerson;
    string email;
    string phone;
    // Add more fields as needed

    Supplier(string _name, float _costOfGoods, string _location, string _contactPerson, string _email, string _phone) 
        : name(_name), costOfGoods(_costOfGoods), location(_location), contactPerson(_contactPerson), email(_email), phone(_phone) {}
};

// Struct to represent edge between suppliers and manufacturer
struct Edge {
    string supplierName;
    float transportationCost;

    Edge(string _supplierName, float _transportationCost) : supplierName(_supplierName), transportationCost(_transportationCost) {}
};

// Class to manage inventory and product flow economics
class InventoryManager {
private:
    unordered_map<string, Supplier> suppliers;
    unordered_map<string, vector<Edge>> supplierEdges; // Graph representation of suppliers and transportation costs

public:
    void addSupplier(string name, float costOfGoods, string location, string contactPerson, string email, string phone) {
        suppliers[name] = {name, costOfGoods, location, contactPerson, email, phone};
    }

    void addTransportationCost(string supplierName, string targetSupplierName, float transportationCost) {
        if (suppliers.find(targetSupplierName) != suppliers.end()) {
            supplierEdges[supplierName].push_back({targetSupplierName, transportationCost});
        } else {
            cout << "Target supplier not found." << endl;
        }
    }

    void displaySuppliers() {
        cout << "Suppliers:\n";
        for (const auto& supplier : suppliers) {
            cout << "Name: " << supplier.second.name << ", Cost of Goods: $" << supplier.second.costOfGoods 
                 << ", Location: " << supplier.second.location << ", Contact Person: " << supplier.second.contactPerson 
                 << ", Email: " << supplier.second.email << ", Phone: " << supplier.second.phone << endl;
        }
    }

    void displayTransportationCosts() {
        cout << "Transportation Costs:\n";
        for (const auto& entry : supplierEdges) {
            cout << "From " << entry.first << ":\n";
            for (const auto& edge : entry.second) {
                cout << "  - To " << edge.supplierName << ": $" << edge.transportationCost << endl;
            }
        }
    }
};

int main() {
    InventoryManager manager;

    // Add suppliers with additional fields
    manager.addSupplier("Supplier A", 1000, "Location A", "John Doe", "john@example.com", "123-456-7890");
    manager.addSupplier("Supplier B", 1200, "Location B", "Jane Smith", "jane@example.com", "987-654-3210");
    manager.addSupplier("Supplier C", 1100, "Location C", "Bob Johnson", "bob@example.com", "555-555-5555");

    // Add transportation costs between suppliers
    manager.addTransportationCost("Supplier A", "Supplier B", 200);
    manager.addTransportationCost("Supplier A", "Supplier C", 250);
    manager.addTransportationCost("Supplier B", "Supplier C", 150);

    manager.displaySuppliers();
    manager.displayTransportationCosts();

    return 0;
}
