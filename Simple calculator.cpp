/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

// Function to perform addition
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to perform subtraction
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to perform multiplication
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to perform division
double divide(double num1, double num2) {
    if (num2 == 0) {
        std::cerr << "Error: Division by zero is not allowed." << std::endl;
        exit(1); // Exit the program with an error code
    }
    return num1 / num2;
}
int main() {
    double num1, num2;
    char operation;

    std::cout << "Simple Calculator Program" << std::endl;
    std::cout << "---------------------------" << std::endl;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    switch (operation) {
        case '+':
            std::cout << "Result: " << add(num1, num2) << std::endl;
            break;
        case '-':
            std::cout << "Result: " << subtract(num1, num2) << std::endl;
            break;
        case '*':
            std::cout << "Result: " << multiply(num1, num2) << std::endl;
            break;
        case '/':
            std::cout << "Result: " << divide(num1, num2) << std::endl;
            break;
        default:
            std::cerr << "Error: Invalid operation. Please use +, -, *, or /." << std::endl;
            break;
    }

    return 0;
}