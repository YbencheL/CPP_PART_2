#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : name("Default"), sign(false), s_grade(50), e_grade(50)
{
    if ((s_grade < 1) || (e_grade < 1))
        throw GradeTooHighException();
    if ((s_grade > 150) || (e_grade > 150))
        throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) : name(obj.name), sign(obj.sign), s_grade(obj.s_grade), e_grade(obj.e_grade)
{
    if ((s_grade < 1) || (e_grade < 1))
        throw GradeTooHighException();
    if ((s_grade > 150) || (e_grade > 150))
        throw GradeTooLowException();
}

AForm::AForm(const std::string& name, const int s_grade, const int e_grade) : name(name), sign(false),
s_grade(s_grade), e_grade(e_grade)
{
    if ((s_grade < 1) || (e_grade < 1))
        throw GradeTooHighException();
    if ((s_grade > 150) || (e_grade > 150))
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& obj)
{
    if (this != &obj)
        sign = obj.sign;
    return *this;
}

AForm::~AForm()
{
    // std::cout << "Destructor called" << std::endl;
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getSign() const
{
    return sign;
}

const int& AForm::getSgrade() const
{
    return s_grade;
}

const int& AForm::getEgrade() const
{
    return e_grade;
}

void AForm::beSigned(const Bureaucrat& bero)
{
    if (bero.getGrade() <= s_grade && !sign)
        sign = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "Form name: " << obj.getName()
       << ", Signed: " << std::boolalpha << obj.getSign()
       << ", Grade to sign: " << obj.getSgrade()
       << ", Grade to execute: " << obj.getEgrade();
    return os;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (sign)
    {
        if (executor.getGrade() <= e_grade)
        {
            executeAction();
        }else
        {
            std::cout << "Failed to execute form " << getName() << " ";
            throw GradeTooLowException();
        }
    }
    else
    {
        std::cout << "Form " << getName();
        throw FormNotSignedException();
    }
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return " is not signed";
}