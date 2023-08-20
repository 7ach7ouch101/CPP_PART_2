/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:24:27 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 01:01:52 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Defaut", false,145, 137), target("Default")
{
    std::cout << "Default constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("test", false, 145, 137), target(target)
{
    std::cout << "constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->target = obj.target;
    return *this;
}

const char* ShrubberyCreationForm::isFormSigned::what() const throw()
{
    return "Form not signed.";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if(( this->getSign()) == false) 
        throw isFormSigned();
    if( (executor.getGrade()) > (this->getGradeexe()) )
        throw GradeTooLowException();

    std::ofstream outfile(this->target + "_shrubbery");
    outfile << "       _-_    \n";
    outfile << "    /~~   ~~\\ \n";
    outfile << " /~~         ~~\\ \n";
    outfile << "{               } \n";
    outfile << " \\  _-     -_  / \n";
    outfile << "   ~  \\\\ //  ~ \n";
    outfile << "_- -   | | _- _ \n";
    outfile << "  _ -  | |   -_ \n";
    outfile << "      // \\\\ \\\n";

    outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor called" << std::endl;
}