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
                const char* what() const throw() {
                    return "Grade is too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return "Grade is too low";
                }
        };
        void signForm(AForm& AForm);
        void executeForm(const AForm  & AForm);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif