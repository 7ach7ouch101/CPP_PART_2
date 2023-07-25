/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:40:53 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/21 10:10:28 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool sign;
        const unsigned grade_sign;
        const unsigned grade_exe;
    public:
        Form(const std::string name, bool sign, const int grade_sign, const int grade_exe);
        Form();
        ~Form();
        Form(const Form &form);
        Form & operator=(const Form &form);
        const std::string getName() const;
        const bool getSign() const;
        const unsigned getGradesign() const;
        const unsigned getGradeexe() const;
        void    beSigned(Bureaucrat &bureaucrat);
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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif