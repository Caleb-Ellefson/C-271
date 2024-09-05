#include <iostream>
#include <iomanip>
#include <string>

int days;
float booking = 19.99;
float day_price = 29.99;
float tax = 0.10;
float paid, subtotal, total, change_due;
std::string name;

void error();
float calculate(float booking, float day_price, int days);
float change(float paid, float total);
void receipt(std::string name, float subtotal, int days, float total, float paid, float change_due);

int main() {
	std::cout << "Welcome! Please enter the following information to create your reservation: \n" << std::endl;
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;

    if (name.length() <= 0 || name.length() > 20) {
        error();
        return 1;
    }

    std::cout << "How many days do you plan on staying?" << std::endl;
    std::cin >> days;

    if (days <= 0) {
        error();
        return 1;
    }

    subtotal = calculate(booking, day_price, days);
    total = subtotal + (subtotal * tax); 

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your total is: $" << total << std::endl;

    std::cout << "How much would you like to pay?" << std::endl;
    std::cin >> paid;

    if (paid <= 0 || paid < total) {
        std::cout << "Not enough order has been cancelled." << std::endl;
        return 1;
    }

    change_due = change(paid, total);
    receipt(name, subtotal, days, total, paid, change_due);

    return 0;
}

void error() {
    std::cout << "Error: invalid input." << std::endl;
}

float calculate(float booking, float day_price, int days) {
    return (days * day_price) + booking;
}

float change(float paid, float total) {
    return paid - total;
}

void receipt(std::string name, float subtotal, int days, float total, float paid, float change_due) {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n---------- RECEIPT ----------";
    std::cout << "NAME: " << name << std::endl;
    std::cout << "# NIGHTS: " << days << std::endl;
    std::cout << "SUBTOTAL: $" << subtotal << std::endl;
    std::cout << "TAX: $" << (subtotal * tax) << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << "TOTAL: $" << total << std::endl;
    std::cout << "----------\n" << std::endl;
    std::cout << "AMOUNT PAID: $" << paid << std::endl;
    std::cout << "CHANGE DUE: $" << change_due << std::endl;
    std::cout << "\n----------THANK YOU FOR RENTING WITH US ----------\n";
}

