#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Product {
private:
    int productID;
    string name;
    float price;

public:
   
    Product(int id = 0, string n = "Unknown", float p = 0.0f) {
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


class Customer {
private:
    int customerID;
    string name;

public:
    
    Customer(int id = 0, string n = "Guest") {
        customerID = id;
        name = n;
    }

    void displayCustomer() {
        cout << "Customer ID: " << customerID << ", Name: " << name << endl;
    }
};


class Order {
private:
    Customer customer;
    vector<Product> cart;

public:
    Order(Customer c = Customer()) : customer(c) {
        cout << "Order created!" << endl;
    }

    void addProduct(Product p = Product()) {
        cart.push_back(p);
    }

    void showOrder() {
        cout << "\n--- Order Details ---\n";
        customer.displayCustomer();
        cout << "Items in Cart: " << cart.size() << endl;

        float total = 0.0;
        for (auto p : cart) {
            p.displayProduct();
            total += p.getPrice();
        }

        cout << "Total Amount: ₹" << total << endl;
    }
};


int main() {
    
    Product p1(101, "Smartphone", 15999.99);
    Product p2(102, "Headphones", 1999.50);
    Product p3(103, "Keyboard", 899.99);


    Customer c1(1, "Dhiya Vinu");

    
    Order order1(c1);
    order1.addProduct(p1);
    order1.addProduct(p2);

   
    order1.addProduct(); 

   
    order1.showOrder();

    return 0;
}
