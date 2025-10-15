#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj)
{
    target = obj.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
        target = obj.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137)
{
    this->target = target;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = getName() + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        throw std::runtime_error("ERROR OPENING OUTPUT FILE");
        return;
    }
    outfile << "                                                 .  "<< std::endl;
    outfile << "                                      .         ;    "<< std::endl;
    outfile << "         .              .              ;%     ;;"<< std::endl;
    outfile << "           ,           ,                :;%  %;     "<< std::endl;
    outfile << "            :         ;                   :;%;'     .,     "<< std::endl;
    outfile << "   ,.        %;     %;            ;        %;'    ,;  "<< std::endl;
    outfile << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'  "<< std::endl;
    outfile << "      %;       %;%;      ,  ;       %;  ;%;   ,%;'   "<< std::endl;
    outfile << "       ;%;      %;        ;%;        % ;%;  ,%;'  "<< std::endl;
    outfile << "        `%;.     ;%;     %;'         `;%%;.%;'  "<< std::endl;
    outfile << "         `:;%.    ;%%. %@;        %; ;@%;%' "<< std::endl;
    outfile << "            `:%;.  :;bd%;          %;@%;'  "<< std::endl;
    outfile << "              `@%:.  :;%.         ;@@%;'     "<< std::endl;
    outfile << "                `@%.  `;@%.      ;@@%;           "<< std::endl;
    outfile << "                  `@%%. `@%%    ;@@%;          "<< std::endl;
    outfile << "                    ;@%. :@%%  %@@%;         "<< std::endl;
    outfile << "                      %@bd%%%bd%%:;       "<< std::endl;
    outfile << "                        #@%%%%%:;;  "<< std::endl;
    outfile << "                        %@@%%%::;  "<< std::endl;
    outfile << "                        %@@@%(o);  . '"<< std::endl;
    outfile << "                        %@@@o%;:(.,'"<< std::endl;
    outfile << "                    `.. %@@@o%::;"<< std::endl;
    outfile << "                       `)@@@o%::;"<< std::endl;
    outfile << "                        %@@(o)::;"<< std::endl;
    outfile << "                       .%@@@@%::;"<< std::endl;
    outfile << "                       ;%@@@@%::;."<< std::endl;
    outfile << "                      ;%@@@@%%:;;;.   "<< std::endl;
    outfile << "                  ...;%@@@@@%%:;;;;,..   "<< std::endl;
}
