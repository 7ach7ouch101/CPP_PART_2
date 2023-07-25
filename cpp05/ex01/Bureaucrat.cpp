/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:47 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/21 10:21:22 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(name)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = bureaucrat;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->grade = bureaucrat.grade;
    return (*this);
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string const name) : name(name)
{
    std::cout << "constructor called" << std::endl;
    if(grade < 1)
        throw  GradeTooLowException();
    if(grade > 150)
        throw GradeTooHighException();
    this->grade = grade;
}

void    Bureaucrat::inc_Grade()
{
    if((this->grade - 1) < 1)
        throw GradeTooHighException();
    else
        this->grade = this->grade - 1;
}

void    Bureaucrat::dec_Grade()
{
    if((this->grade + 1) > 150)
        throw GradeTooLowException();
    else
        this->grade = this->grade + 1;
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

unsigned    Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::signForm(Form &form)
{
    if(form.getSign() == true)
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else
         std::cout << this->name << " couldn't sign " << form.getName() << " because " << "Grade is too Loww" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}