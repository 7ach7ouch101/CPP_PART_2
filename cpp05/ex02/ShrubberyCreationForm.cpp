
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default shushu", 145, 137), target("Default")
{
    std::cout << "Default constructor for ShrubberyCreationForm is called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shushu form", 145, 137), target(target)
{
    std::cout << "Parametrized Constructor for ShrubberyCreationForm is called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : AForm(obj.getName(), 145, 137)
{
    std::cout << "Copy Constructor is called for ShrubberyCreationForm" << std::endl;
    *this = obj;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
    std::cout << "Operator is called for ShrubberyCreationForm" << std::endl;
    this->target = obj.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm constructor is called!" << std::endl;
}