#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    private:

        const std::string   name;
        int                 grade;

    public:

        Bureaucrat();
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat& operator=(const Bureaucrat& obj);
        ~Bureaucrat();
        const std::string&  getName() const;
        int                 getGrade() const;
        void                incrementGrade(); 
        void                decrementGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        }; 
        void signForm(AForm& AForm);
        void executeForm(AForm const & AForm);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif