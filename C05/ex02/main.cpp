#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("robot");
    PresidentialPardonForm pardon("Alice");
    
    try
    {
        Bureaucrat bob("Bob", 1); 
        std::cout << "\n--- Signing form 1 ---\n";
        bob.signForm(shrubbery);
        std::cout << "\n--- Executing form 1 ---\n";
        bob.executeForm(shrubbery);
        std::cout << "\n--- Executing unsigned form ---\n";
        bob.executeForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat alice("Alice", 40);
        std::cout << "\n--- Signing forms 2 ---\n";
        alice.signForm(robotomy);
        std::cout << "\n--- Executing forms 2 ---\n";
        alice.executeForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat carol("Carol", 4);
        std::cout << "\n--- Signing forms 3 ---\n";
        carol.signForm(pardon);
        std::cout << "\n--- Executing forms 3 ---\n";
        carol.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    

    std::cout << "\n---Destructors---\n";
    return 0;
}
