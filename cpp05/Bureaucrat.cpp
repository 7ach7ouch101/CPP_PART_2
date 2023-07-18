/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:47 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/18 10:44:42 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


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
    if(grade < 1 || grade > 150)
        throw "Error";
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}