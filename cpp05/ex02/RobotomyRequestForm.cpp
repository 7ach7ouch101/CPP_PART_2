/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:24:23 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 00:44:22 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Defaut", false,72, 45), target("Default")
{
    std::cout << "Default constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", false, 72, 45), target(target)
{
    std::cout << "constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->target = obj.target;
    return *this;
}

const char* RobotomyRequestForm::isFormSigned::what() const throw()
{
    return "Form not signed.";
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if(( this->getSign()) == false) 
        throw isFormSigned();
    if( (executor.getGrade()) > (this->getGradeexe()))
        throw GradeTooLowException();
    
    std::cout << "drilling noises grrrr grrrrr" << std::endl;

    std::srand(std::time(0));
    if ((rand() % 2) == 0) 
    {
        std::cout << target << " been robotomized successfully." << std::endl;
    } 
    else
    {
        std::cout << "robotomized on " << target << " failed." << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor called" << std::endl;
}