#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Bureaucrat creation ===" << std::endl;
    try {
        Bureaucrat b1("yass", 1);
        Bureaucrat b2("mem", 75);
        Bureaucrat b3("cec", 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat creation with invalid grades ===" << std::endl;
    try {
        Bureaucrat b4("TooHigh", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat b5("TooLow", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Increment / Decrement tests ===" << std::endl;
    try {
        Bureaucrat b6("ded", 2);
        b6.incrementGrade();
        std::cout << b6 << std::endl;
        b6.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b7("fef", 149);
        b7.decrementGrade();
        std::cout << b7 << std::endl;
        b7.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Form creation ===" << std::endl;
    try {
        Form f1("Simple", 100, 50);
        Form f2("NotsoSimple", 10, 5);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        Bureaucrat signer("rer", 20);

        std::cout << "\n=== Signing forms ===" << std::endl;
        signer.signForm(f1);
        signer.signForm(f2);

        std::cout << "\nAfter signing attempts:" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
