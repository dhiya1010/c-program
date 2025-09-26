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
    Product() : productID(0), name("Unknown"), price(0.0f) {
        productCount++;
    }

    Product(int id, string n, float p) : productID(id), name(n), price(p) {
        productCount++;
    }

    Product(const Product& other) {
        productID = other.productID;
        name = other.name;
        price = other.price;
        productCount++;
    }

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

    Product& operator++() {
        price += 100.0f;
        return *this;
    }

    Product& operator--() {
        price -= 100.0f;
        return *this;
    }

    void operator!() {
        if (name == "Unavailable")
            name = "Available";
        else
            name = "Unavailable";
    }

        Product operator+(const Product& other) const {
        int newID = this->productID + other.productID;
        string newName = this->name + " & " + other.name;
        float newPrice = this->price + other.price;
        return Product(newID, newName, newPrice);
    }
};

int Product::productCount = 0;

class Customer {
private:
    int customerID;
    string name;

public:
    Customer() : customerID(0), name("Guest") {}

    Customer(int id, string n) : customerID(id), name(n) {}

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
    Order() : customer(Customer()) {
        cout << "Default Order created!" << endl;
    }

    Order(Customer c) : customer(c) {
        cout << "Order created for customer!" << endl;
    }

    Order(const Order& other) : customer(other.customer), cart(other.cart) {
        cout << "Order copied!" << endl;
    }

    void addProduct(Product p = Product()) {
        cart.push_back(p);
        cout << "Product '" << p.getName() << "' added to cart." << endl;
    }

    void addProduct(int id, string n, float p) {
        Product newProduct(id, n, p);
        cart.push_back(newProduct);
        cout << "Product '" << n << "' added to cart with details." << endl;
    }

    void addProduct(string n) {
        Product newProduct(999, n, 0.0f);
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

void printOrderSummary(const Order& o) {
    float total = 0.0;
    for (const auto& p : o.cart) {
        total += p.getPrice();
    }

    cout << "\n[Order Summary]" << endl;
    cout << "Customer: " << o.customer.getName() << endl;
    cout << "Items Ordered: " << o.cart.size() << endl;
    cout << "Total Amount: ₹" << total << endl;
}

int main() {
    Product p1(101, "Smartphone", 15999.99);
    Product p2(102, "Headphones", 1999.50);
    Product p3(103, "Keyboard", 899.99);

    Product p4 = p1;

    cout << "\nTotal Products Created: " << Product::getProductCount() << endl;

    Customer c1(1, "Dhiya Vinu");

    Order order1(c1);

    order1.addProduct(p1);
    order1.addProduct(p2);
    order1.addProduct();

    order1.addProduct(104, "Mouse", 499.00);
    order1.addProduct("USB Cable");

    order1.showOrder();

    Order order2 = order1;
    order2.showOrder();

    printOrderSummary(order1);

    cout << "\n--- Product Operations ---\n";
    p3.displayProduct();

    ++p3;
    p3.displayProduct();

    --p3;
    p3.displayProduct();

    !p3;
    p3.displayProduct();

    p1.displayProduct(false);

    Product bundle = p1 + p2;
    cout << "\n--- Bundle Product (p1 + p2) ---\n";
    bundle.displayProduct();

    cout << "\nTotal Products Created: " << Product::getProductCount() << endl;

    return 0;
}

