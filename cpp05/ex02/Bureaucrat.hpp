/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:52 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/25 02:35:17 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        unsigned        grade;
    public:
        Bureaucrat(unsigned int grade, std::string name);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &Bureaucrat);
        Bureaucrat & operator=(const Bureaucrat &Bureaucrat);
        const std::string getName() const;
        unsigned  getGrade() const;
        void    inc_Grade();
        void    dec_Grade();
        void    signForm(AForm &form);
        void    executeForm(AForm const & form);
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