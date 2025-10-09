#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name("Default"), sign(false), s_grade(50), e_grade(50)
{
    if ((s_grade < 1) || (e_grade < 1))
        throw GradeTooHighException();
    if ((s_grade > 150) || (e_grade > 150))
        throw GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), sign(obj.sign), s_grade(obj.s_grade), e_grade(obj.e_grade)
{
    if ((s_grade < 1) || (e_grade < 1))
        throw GradeTooHighException();
    if ((s_grade > 150) || (e_grade > 150))
        throw GradeTooLowException();
}

Form::Form(const std::string& name, const int s_grade, const int e_grade) : name(name), sign(false),
s_grade(s_grade), e_grade(e_grade)
{
    if ((s_grade < 1) || (e_grade < 1))
        throw GradeTooHighException();
    if ((s_grade > 150) || (e_grade > 150))
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
        sign = obj.sign;
    return *this;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getSign() const
{
    return sign;
}

const int& Form::getSgrade() const
{
    return s_grade;
}

const int& Form::getEgrade() const
{
    return e_grade;
}

void Form::beSigned(const Bureaucrat& bero)
{
    if (bero.getGrade() <= s_grade && !sign)
        sign = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form name: " << obj.getName()
       << ", Signed: " << std::boolalpha << obj.getSign()
       << ", Grade to sign: " << obj.getSgrade()
       << ", Grade to execute: " << obj.getEgrade();
    return os;
}