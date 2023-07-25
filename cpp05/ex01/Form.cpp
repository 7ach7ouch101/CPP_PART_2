/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:40:55 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/24 23:22:11 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, bool sign, const int grade_sign, const int grade_exe) : name(name), sign(false), grade_sign(grade_sign), grade_exe(grade_exe)
{
    std::cout << "constructor called" << std::endl;
    if(grade_sign < 1 || grade_exe < 1)
        throw GradeTooHighException();
    else if(grade_sign > 150|| grade_exe > 150)
        throw GradeTooLowException();
}

Form::Form() : name("Default"), sign(false), grade_sign(1), grade_exe(1)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form &form) : name(name), sign(false), grade_sign(grade_sign), grade_exe(grade_exe)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = form;
}

Form & Form::operator=(const Form &form)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->sign = form.sign;
    return (*this);
}

const std::string Form::getName() const
{
    return (this->name);
}

const bool Form::getSign() const
{
    return (this->sign);
}

const unsigned Form::getGradesign() const
{
    return (this->grade_sign);
}

const unsigned Form::getGradeexe() const
{
    return (this->grade_exe);
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= (this->grade_sign))
        this->sign = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	if (form.getSign() == true)
		os << "Form " << form.getName() << " is successfully signed !!\n";
	else
		os << "Form " << form.getName() << " is not signed !!\n";
	return (os);
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}