#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
    target = obj.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
        target = obj.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45)
{
    this->target = target;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "***LOUD DRILLING NOISES***" << std::endl;
    int rando = rand();
    if (rando % 2 == 0)
        std::cout << target << " HAS BEEN ROBOTOMIZED SUCCESSFULLY" << std::endl;
    else
        std::cout << target << " FAILED TO ROBOTOMIZE" << std::endl;
}
