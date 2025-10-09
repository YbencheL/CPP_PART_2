#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat bob("Bob", 1);   
    Bureaucrat alice("Alice", 50);
    Bureaucrat carol("Carol", 150);
    
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("robot");
    PresidentialPardonForm pardon("Alice");

    std::cout << "\n--- Signing forms ---\n";
    bob.signForm(shrubbery);
    alice.signForm(robotomy);
    carol.signForm(pardon);

    std::cout << "\n--- Executing forms ---\n";
    bob.executeForm(shrubbery);
    alice.executeForm(robotomy);
    carol.executeForm(pardon);
    ShrubberyCreationForm unsignedForm("garden");
    std::cout << "\n--- Executing unsigned form ---\n";
    bob.executeForm(unsignedForm);

    std::cout << "\n---Destructors---\n";
    return 0;
}
