#include <iostream>
#include <limits>

// Function declarations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero is not allowed." << std::endl;
        return 0;
    }
    return a / b;
}

// Function to safely get numeric input
double getNumber() {
    double num;
    while (true) {
        std::cin >> num;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear(); // clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return num;
        }
    }
}

int main() {
    double num1, num2;
    char op;

    std::cout << "Simple Calculator\n";

    std::cout << "Enter first number: ";
    num1 = getNumber();

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    num2 = getNumber();

    double result;

    switch (op) {
        case '+':
            result = add(num1, num2);
            std::cout << "Result: " << result << std::endl;
            break;
        case '-':
            result = subtract(num1, num2);
            std::cout << "Result: " << result << std::endl;
            break;
        case '*':
            result = multiply(num1, num2);
            std::cout << "Result: " << result << std::endl;
            break;
        case '/':
            result = divide(num1, num2);
            if (num2 != 0)
                std::cout << "Result: " << result << std::endl;
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
    }

    return 0;
}
