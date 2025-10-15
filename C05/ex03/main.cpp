#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    {
        try
        {
            std::cout << "\n--- Intern creating forms ---\n";
            Intern someRandomIntern;
            AForm* rrf;
            Bureaucrat yass("yass", 5);
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            yass.signForm(*rrf);
            delete rrf;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        try
        {
            std::cout << "\n--- Intern creating forms ---\n";
            Intern someRandomIntern;
            AForm* rrf;
            Bureaucrat vass("vass", 50);
            rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
            vass.signForm(*rrf);
            delete rrf;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // ShrubberyCreationForm shrubbery("home");
    // RobotomyRequestForm robotomy("robot");
    // PresidentialPardonForm pardon("Alice");
    // try
    // {
    //     Bureaucrat bob("Bob", 1); 
    //     std::cout << "\n--- Signing form 1 ---\n";
    //     bob.signForm(shrubbery);
    //     std::cout << "\n--- Executing form 1 ---\n";
    //     bob.executeForm(shrubbery);
    //     ShrubberyCreationForm unsignedForm("garden");
    //     std::cout << "\n--- Executing unsigned form 1 ---\n";
    //     bob.executeForm(unsignedForm);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     Bureaucrat alice("Alice", 50);
    //     std::cout << "\n--- Signing forms 2 ---\n";
    //     alice.signForm(robotomy);
    //     std::cout << "\n--- Executing forms 2 ---\n";
    //     alice.executeForm(robotomy);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     Bureaucrat carol("Carol", 150);
    //     std::cout << "\n--- Signing forms 3 ---\n";
    //     carol.signForm(pardon);
    //     std::cout << "\n--- Executing forms 3 ---\n";
    //     carol.executeForm(pardon);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }    

    return 0;
}
