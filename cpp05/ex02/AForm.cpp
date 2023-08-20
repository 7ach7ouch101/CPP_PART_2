/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:40:55 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 00:43:34 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, bool sign, const int grade_sign, const int grade_exe) : name(name),grade_sign(grade_sign), grade_exe(grade_exe)
{
    sign = false;
    std::cout << "constructor called" << std::endl;
    if(grade_sign < 1 || grade_exe < 1)
        throw GradeTooHighException();
    else if(grade_sign > 150|| grade_exe > 150)
        throw GradeTooLowException();
}

AForm::AForm() : name("Default"), sign(false), grade_sign(1), grade_exe(1)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const AForm &form) : grade_sign(form.grade_sign), grade_exe(form.grade_exe)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = form;
}

AForm & AForm::operator=(const AForm &form)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->sign = form.sign;
    return (*this);
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSign() const
{
    return (this->sign);
}

unsigned AForm::getGradesign() const
{
    return (this->grade_sign);
}

unsigned AForm::getGradeexe() const
{
    return (this->grade_exe);
}

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= (this->grade_sign))
        this->sign = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too Loww";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too High";
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}