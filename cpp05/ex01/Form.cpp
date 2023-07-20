/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:40:55 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/20 04:41:40 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, bool sign, const int grade_sign, const int grade_exe) : name(name), sign(false), grade_sign(grade_sign), grade_exe(grade_exe)
{
    if(grade_sign < 1 || grade_exe < 1)
        throw GradeTooLowException();
    else if(grade_sign > 150|| grade_exe > 150)
        throw GradeTooHighException();
}

Form::Form()
{
    std::cout << "Default constructor called" << std::endl;
}

// Form::Form(const Form &Form)
// {
//     std::cout << "Copy constructor called" << std::endl;
//     (*this) = Form;
// }

Form & Form::operator=(const Form &Form)
{
    std::cout << "Copy assignment operator called" << std::endl;
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

const int Form::getGradesign() const
{
    return (this->grade_sign);
}

const int Form::getGradeexe() const
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

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}