#include <iostream>
#include <string>


int first;
int second;

int* ptr1 = &first;
int* ptr2 = &second;

void swap_by_reference(int &ptr1, int &ptr2);
void swap_by_pointer(int* ptr1, int* ptr2);
void null_the_ptrs(int* &ptr1, int* &ptr2);

int main() {
    std::cout << "Enter first number: " << std::endl;
    std::cin >> first;

    std::cout << "Enter second number: " << std::endl;
    std::cin >> second;

    std::cout << "Before Swapping: " << std::endl;
    std::cout << "First number: " << first << std::endl;
    std::cout << "The address of first number: " << ptr1 << std::endl;

    std::cout << "Second number: " << second << std::endl;
    std::cout << "The address of second number: " << ptr2 << std::endl;

    std::cout << "After swapping by reference: " << std::endl;
    swap_by_reference(first, second);

    std::cout << "First number: " << first << std::endl;
    std::cout << "The address of first number: " << ptr1 << std::endl;

    std::cout << "Second number: " << second << std::endl;
    std::cout << "The address of second number: " << ptr2 << std::endl;

    std::cout << "After swapping by pointer: " << std::endl;
    swap_by_pointer(ptr1, ptr2);

    std::cout << "First number: " << first << std::endl;
    std::cout << "The address of first number: " << ptr1 << std::endl;


    std::cout << "Second number: " << second << std::endl;
    std::cout << "The address of second number: " << ptr2 << std::endl;

    return 0;
}

void swap_by_reference(int &ptr1, int &ptr2) {
    int temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

void swap_by_pointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

