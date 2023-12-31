/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:24:29 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 00:16:11 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &obj);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &obj);
        ~ShrubberyCreationForm();
        void execute(const Bureaucrat& executor) const;
        class isFormSigned : public std::exception
        {
            public:
                const char* what() const throw();
        };
};