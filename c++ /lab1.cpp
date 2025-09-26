#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class for Product
class Product {
private:
    int productID;
    string name;
    float price;

public:
    Product(int id, string n, float p) {
        productID = id;
        name = n;
        price = p;
    }

    void displayProduct() {
        cout << "Product ID: " << productID << ", Name: " << name << ", Price: ₹" << price << endl;
    }

    float getPrice() {
        return price;
    }

    string getName() {
        return name;
    }
};

// Class for Customer
class Customer {
private:
    int customerID;
    string name;

public:
    Customer(int id, string n) {
        customerID = id;
        name = n;
    }

    void displayCustomer() {
        cout << "Customer ID: " << customerID << ", Name: " << name << endl;
    }
};

// Class for Order
class Order {
private:
    Customer customer;
    vector<Product> cart;

public:
    Order(Customer c) : customer(c) {
        cout<<"Order created!";
    }

    void addProduct(Product p) {
        cart.push_back(p);
    }

    void showOrder() {
        cout << "\n--- Order Details ---\n";
        customer.displayCustomer();
        cout << "Items in Cart:5\n";

        float total = 0.0;
        for (auto p : cart) {
            p.displayProduct();
            total += p.getPrice();
        }

        cout << "Total Amount: ₹" << total << endl;
    }
};

// Main Function
int main() {
    // Create some products
    Product p1(101, "Smartphone", 15999.99);
    Product p2(102, "Headphones", 1999.50);
    Product p3(103, "Keyboard", 899.99);

    // Create a customer
    Customer c1(1, "Dhiya Vinu");

    // Create an order for the customer
    Order order1(c1);
    order1.addProduct(p1);
    order1.addProduct(p2);

    // Display the order
    order1.showOrder();

    return 0;
