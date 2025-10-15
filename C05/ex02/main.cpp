#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    ShrubberyCreationForm shrubbery("shrub");
    RobotomyRequestForm robotomy("robot");
    PresidentialPardonForm pardon("Xi");
    
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
        Bureaucrat gene("Gene", 40);
        std::cout << "\n--- Signing forms 2 ---\n";
        gene.signForm(robotomy);
        std::cout << "\n--- Executing forms 2 ---\n";
        gene.executeForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat arthur("Arthur", 4);
        std::cout << "\n--- Signing forms 3 ---\n";
        arthur.signForm(pardon);
        std::cout << "\n--- Executing forms 3 ---\n";
        arthur.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    

    std::cout << "\n---Destructors---\n";
    return 0;
}
