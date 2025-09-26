#include <iostream>
using namespace std;


class User {
protected:
    string name;
    string email;
public:
    void getUserDetails() {
       
        cout << "\nEnter User Name: ";
        cin >> name;
        cout << "Enter Email: ";
        cin >> email;
    }
    void displayUserDetails() {
       
        cout << "Name: " << name << "\nEmail: " << email << endl;
    }
};


class Customer : public User {
protected:
    int customerID;
    string name;
public:
    void getCustomerDetails() {
        cout << "\nEnter Customer ID: ";
        cin >> customerID;
    }
    void displayCustomerDetails() {
        displayUserDetails();
        cout << "Customer ID: " << customerID << endl;
    }
};


class Order : public Customer {
private:
    int orderID;
    string product;
    float price;
public:
    void getOrderDetails() {
        cout << "\nEnter Order ID: ";
        cin >> orderID;
        cout << "Enter Product Name: ";
        cin >> product;
        cout << "Enter Price: ";
        cin >> price;
    }
    void displayOrderDetails() {
        cout <<"\n--ORDER DETAILS--\n";
        displayCustomerDetails();
        cout << "Order ID: " << orderID << "\nProduct: " << product 
             << "\nPrice: " << price << endl;
    }
};

int main() {
    Order o;
    cout << "--Online Shopping System --\n";
    o.getUserDetails();
    o.getCustomerDetails();
    o.getOrderDetails();

    cout << "\n--SUMMARY--";
    o.displayOrderDetails();

    return 0;
}

