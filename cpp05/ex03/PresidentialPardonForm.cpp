/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:24:19 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/25 02:32:20 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", false, 25, 5), target("Default")
{
    std::cout << "Default constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("test", false, 25, 5), target(target)
{
    std::cout << "constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if(( this->getSign()) == false) 
        throw std::runtime_error("Form not signed.");
    if( (executor.getGrade()) > (this->getGradeexe()))
        throw GradeTooLowException();

    std::cout << this->target << " been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor called" << std::endl;
}