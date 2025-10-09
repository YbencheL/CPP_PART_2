#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;
class Form
{
    private:

        const std::string   name;
        bool                sign;
        const int           s_grade;
        const int           e_grade;

    public:

        Form();
        Form(const Form& obj);
        Form(const std::string& name, const int s_grade, const int e_grade);
        Form& operator=(const Form& obj);
        ~Form();
        const std::string& getName() const;
        bool getSign() const;
        const int& getSgrade() const;
        const int& getEgrade() const;
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
        void beSigned(const Bureaucrat& bero);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif