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
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        unsigned int grade;
    public:
        void    signForm(AForm &form);
        Bureaucrat(unsigned int grade, std::string name);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &Bureaucrat);
        Bureaucrat & operator=(const Bureaucrat &Bureaucrat);
        const std::string getName() const;
        int getGrade();
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

//needs << operator

#endif