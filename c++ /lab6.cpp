#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    int productID;
    string name;
    float price;

    static int productCount;

public:
    // Default constructor
    Product() : productID(0), name("Unknown"), price(0.0f) {
        productCount++;
    }

    // Parameterized constructor
    Product(int id, string n, float p) : productID(id), name(n), price(p) {
        productCount++;
    }

    // Copy constructor
    Product(const Product& other) {
        productID = other.productID;
        name = other.name;
        price = other.price;
        productCount++;
    }

    // Function Overloading: displayProduct()
    void displayProduct() const {
        cout << "Product ID: " << productID << ", Name: " << name << ", Price: ₹" << price << endl;
    }

    void displayProduct(bool showPrice) const {
        cout << "Product ID: " << productID << ", Name: " << name;
        if (showPrice) {
            cout << ", Price: ₹" << price;
        }
        cout << endl;
    }

    float getPrice() const {
        return price;
    }

    string getName() const {
        return name;
    }

    static int getProductCount() {
        return productCount;
    }
};

int Product::productCount = 0;

class Customer {
private:
    int customerID;
    string name;

public:
    // Default constructor
    Customer() : customerID(0), name("Guest") {}

    // Parameterized constructor
    Customer(int id, string n) : customerID(id), name(n) {}

    // Copy constructor
    Customer(const Customer& other) {
        customerID = other.customerID;
        name = other.name;
    }

    void displayCustomer() const {
        cout << "Customer ID: " << customerID << ", Name: " << name << endl;
    }

    string getName() const {
        return name;
    }
};

class Order {
private:
    Customer customer;
    vector<Product> cart;

public:
    // Default constructor
    Order() : customer(Customer()) {
        cout << "Default Order created!" << endl;
    }

    // Parameterized constructor
    Order(Customer c) : customer(c) {
        cout << "Order created for customer!" << endl;
    }

    // Copy constructor
    Order(const Order& other) : customer(other.customer), cart(other.cart) {
        cout << "Order copied!" << endl;
    }

    // Overloaded addProduct #1: Adds a Product object
    void addProduct(Product p = Product()) {
        cart.push_back(p);
        cout << "Product '" << p.getName() << "' added to cart." << endl;
    }

    // Overloaded addProduct #2: Adds by product details
    void addProduct(int id, string n, float p) {
        Product newProduct(id, n, p);
        cart.push_back(newProduct);
        cout << "Product '" << n << "' added to cart with details." << endl;
    }

    // Overloaded addProduct #3: Adds by name only
    void addProduct(string n) {
        Product newProduct(999, n, 0.0f); // Dummy ID and 0 price
        cart.push_back(newProduct);
        cout << "Product '" << n << "' added with default values." << endl;
    }

    void showOrder() const {
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

    friend void printOrderSummary(const Order& o);
};

// Friend function to access private members
void printOrderSummary(const Order& o) {
    float total = 0.0;
    for (const auto& p : o.cart) {
        total += p.getPrice();
    }

    cout << "\n[Friend Function: Order Summary]" << endl;
    cout << "Customer: " << o.customer.getName() << endl;
    cout << "Items Ordered: " << o.cart.size() << endl;
    cout << "Total Amount: ₹" << total << endl;
}

int main() {
    Product p1(101, "Smartphone", 15999.99);
    Product p2(102, "Headphones", 1999.50);
    Product p3(103, "Keyboard", 899.99);

    // Copy constructor demo
    Product p4 = p1;

    cout << "\nTotal Products Created: " << Product::getProductCount() << endl;

    Customer c1(1, "Dhiya Vinu");

    Order order1(c1);

    // Overloaded addProduct (Product object)
    order1.addProduct(p1);
    order1.addProduct(p2);
    order1.addProduct(); // Adds default product

    // Overloaded addProduct (product details)
    order1.addProduct(104, "Mouse", 499.00); 

    // Overloaded addProduct (name only)
    order1.addProduct("USB Cable");

    order1.showOrder();

    // Copy constructor for Order
    Order order2 = order1;
    order2.showOrder();

    printOrderSummary(order1);

    // Demonstrate overloaded displayProduct
    cout << "\nOverloaded displayProduct with showPrice = false:\n";
    p1.displayProduct(false);

    return 0;
}
