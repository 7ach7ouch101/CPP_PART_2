/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:54 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 00:35:00 by mmeziani         ###   ########.fr       */
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
        Bureaucrat t(2, "hamid");
        RobotomyRequestForm c("salam");
        c.beSigned(t);
        t.executeForm(c);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    try
    {
        Bureaucrat b(100,"hassan");
        ShrubberyCreationForm  a("test");
        a.beSigned(b);
        a.execute(b);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    PresidentialPardonForm b("ma3linaaaa");
    try
    {
        Bureaucrat b(2,"soufiane");
        PresidentialPardonForm c("m7amad");
        c.beSigned(b);
        b.executeForm(c);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}