/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:47 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/25 02:39:08 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = Bureaucrat;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &Bureaucrat)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string const name) : grade(grade), name(name)
{
    std::cout << "constructor called" << std::endl;
    if(grade < 1)
        throw  GradeTooLowException();
    if(grade > 150)
        throw GradeTooHighException();
}

void    Bureaucrat::inc_Grade()
{
    if((this->grade + 1) > 150)
        throw GradeTooHighException();
    else
        this->grade = this->grade + 1;
}

void    Bureaucrat::dec_Grade()
{
    if((this->grade - 1) < 1)
        throw GradeTooLowException();
    else
        this->grade = this->grade - 1;
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

unsigned Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::signForm(AForm &form)
{
    if(form.getSign() == true)
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else
         std::cout << this->name << " couldn't sign " << form.getName() << " because " << "Grade is too Loww" << std::endl;
}

void    Bureaucrat::executeForm(AForm const & form)
{
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}