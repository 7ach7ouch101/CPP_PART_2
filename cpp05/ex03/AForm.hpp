/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:40:53 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/25 00:25:39 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool sign;
        const unsigned grade_sign;
        const unsigned grade_exe;
    public:
        AForm(const std::string name, bool sign, const int grade_sign, const int grade_exe);
        AForm();
        ~AForm();
        AForm(const AForm &Form);
        AForm & operator=(const AForm &Form);
        const std::string getName() const;
        const bool getSign() const;
        const unsigned getGradesign() const;
        const unsigned getGradeexe() const;
        void    beSigned(Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif