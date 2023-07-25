/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:52 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/21 10:06:45 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const name;
        unsigned    grade;
    public:
        void    signForm(Form &form);
        Bureaucrat(unsigned int grade, std::string name);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &Bureaucrat);
        Bureaucrat & operator=(const Bureaucrat &Bureaucrat);
        const std::string getName() const;
        unsigned getGrade() const;
        void    inc_Grade();
        void    dec_Grade();
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too Loww";
                }
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too High";
                }
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif