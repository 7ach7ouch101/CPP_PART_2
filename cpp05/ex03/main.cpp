/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:54 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/25 02:39:34 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main(void)
{
    try
    {
        // ShrubberyCreationForm  a("test");
        //RobotomyRequestForm c("salam");
        // Bureaucrat b(100,"hassan");
        PresidentialPardonForm b("ma3linaaaa");
        Bureaucrat t(2, "hahaha");
        // a.beSigned(b);
        // a.execute(b);
        b.beSigned(t);
        t.executeForm(b);
        // b.execute(t);
        //std::cout << a.getGradeexe() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}