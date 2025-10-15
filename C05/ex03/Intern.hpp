#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

class Intern
{
    public:

        Intern();
        Intern(const Intern& obj);
        Intern& operator=(const Intern& obj);
        ~Intern();
        class FormNotAvb : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        AForm* Robotomy(const std::string& t);
        AForm* presidential(const std::string& t);
        AForm* Shrubbery(const std::string& t);
        AForm* makeForm(std::string FormName, std::string target);
};

 
#endif
