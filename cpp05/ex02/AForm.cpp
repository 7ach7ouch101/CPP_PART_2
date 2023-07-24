/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:40:55 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/21 10:18:01 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, bool sign, const int grade_sign, const int grade_exe) : name(name), sign(false), grade_sign(grade_sign), grade_exe(grade_exe)
{
    std::cout << "constructor called" << std::endl;
    if(grade_sign < 1 || grade_exe < 1)
        throw GradeTooLowException();
    else if(grade_sign > 150|| grade_exe > 150)
        throw GradeTooHighException();
}

AForm::AForm() : name("Default"), sign(false), grade_sign(0), grade_exe(0)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const AForm &Form) : name(Form.name), sign(Form.sign), grade_sign(Form.grade_sign), grade_exe(Form.grade_exe)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm & AForm::operator=(const AForm &Form)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

const std::string AForm::getName() const
{
    return (this->name);
}

const bool AForm::getSign() const
{
    return (this->sign);
}

const int AForm::getGradesign() const
{
    return (this->grade_sign);
}

const int AForm::getGradeexe() const
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

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}