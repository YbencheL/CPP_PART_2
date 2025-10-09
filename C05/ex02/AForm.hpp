#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

class Bureaucrat;
class AForm
{
    private:

        const std::string   name;
        bool                sign;
        const int           s_grade;
        const int           e_grade;

    public:

        AForm();
        AForm(const AForm& obj);
        AForm(const std::string& name, const int s_grade, const int e_grade);
        AForm& operator=(const AForm& obj);
        virtual ~AForm();
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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw() {
                    return " is not signed";
                }
        };
        void beSigned(const Bureaucrat& bero);
        virtual void executeAction() const = 0;
        void execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif