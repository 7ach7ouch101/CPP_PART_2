/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:54 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 01:14:53 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        Bureaucrat b;
        rrf = someRandomIntern.makeForm("shrubbery creation", "scayooooo");
        rrf->beSigned(b);
        rrf->execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        Bureaucrat b;
        rrf = someRandomIntern.makeForm("robotomy request", "bsila toxic");
        rrf->beSigned(b);
        rrf->execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        Bureaucrat b;
        rrf = someRandomIntern.makeForm("shrubbery creation", "waeil");
        rrf->beSigned(b);
        rrf->execute(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "111----------------------" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        Bureaucrat b;
        rrf = someRandomIntern.makeForm("fgdfgdfgdf", "taha");
        rrf->beSigned(b);
        rrf->execute(b);
    }
    catch(std::exception& e)
    {
        std::cerr << "TEST" << std::endl;
        std::cerr << e.what() << std::endl;;
    }
    return (0);
}