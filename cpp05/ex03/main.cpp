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
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm* rrf;
    Bureaucrat b;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf->execute(b);
    return (0);
}