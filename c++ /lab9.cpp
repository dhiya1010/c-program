#include <iostream>
#include <string>
using namespace std;


class Customer {
protected:
    string name;
    string email;
public:
    void getCustomerDetails() {
        cout << "Enter Customer Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
    }
    void showCustomerDetails() {
        cout << "\n--- Customer Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
};


class Product {
protected:
    string name;
    double price;
public:
    void getProductDetails() {
        cout << "\nEnter Product Name: ";
        getline(cin, name);
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
    }
    void showProductDetails() {
        cout << "\n--- Product Details ---" << endl;
        cout << "Product: " << name << endl;
        cout << "Price: $" << price << endl;
    }
};


class Order : public Customer, public Product {
private:
    int quantity;
public:
    void getOrderDetails() {
        getCustomerDetails();
        getProductDetails();
        cout << "Enter Quantity: ";
        cin >> quantity;
    }
    void showOrderDetails() {
        showCustomerDetails();
        showProductDetails();
        cout << "Quantity: " << quantity << endl;
        cout << "Total Amount: $" << price * quantity << endl;
    }
};

int main() {
    Order order;
    order.getOrderDetails();
    cout << "\n===== ORDER SUMMARY =====" << endl;
    order.showOrderDetails();
    return 0;
}

