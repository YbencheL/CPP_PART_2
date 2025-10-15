#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& obj)
{
    (void)obj;
}

Intern& Intern::operator=(const Intern& obj)
{
    (void)obj;
    return *this;
}

Intern::~Intern()
{

}

AForm* Intern::Robotomy(const std::string& t)
{
    return new RobotomyRequestForm(t);
}

AForm* Intern::presidential(const std::string& t)
{
    return new PresidentialPardonForm(t);
}

AForm* Intern::Shrubbery(const std::string& t)
{
    return new ShrubberyCreationForm(t);
}

AForm* Intern::makeForm(std::string FormName, std::string target)
{
    const char* AvbFroms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (Intern::*arr2[])(const std::string& t) = {&Intern::Robotomy, &Intern::presidential ,&Intern::Shrubbery};

    int i = 0;
    if(FormName != AvbFroms[0] && FormName != AvbFroms[1] && FormName != AvbFroms[2])
    {
        std::cout << FormName;
        throw FormNotAvb();
    }
    while(FormName != AvbFroms[i] && i < 3)
        i++;
    std::cout << "Intern creates " << FormName << std::endl;
    return (this->*arr2[i])(target);
}