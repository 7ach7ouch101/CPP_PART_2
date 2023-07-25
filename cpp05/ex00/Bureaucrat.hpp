/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:52 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/20 02:34:18 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        std::string const name;
        unsigned    grade;
    public:
        Bureaucrat(unsigned int grade, std::string name);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat & operator=(const Bureaucrat &bureaucrat);
        const std::string getName() const;
        unsigned    getGrade() const ;
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