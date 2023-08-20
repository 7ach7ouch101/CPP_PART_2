/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:54 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 00:05:07 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form t("ghost",false,3,3);
        Form a;
        Bureaucrat y(1, "si hamid");
        t.beSigned(y);
        y.signForm(t);
        a = t;
        std::cout << a;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form t("ghost",false,3,3);
        Bureaucrat y(1, "si hamid");
        t.beSigned(y);
        y.signForm(t);
        std::cout << t;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    try
    {
        Form t("ghost",false,1,1);
        Bureaucrat y(2, "si hamid");
        std::cout << t;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    try
    {
        Form t("ghost",false,111,111);
        Bureaucrat y(1, "si hamid");
        t.beSigned(y);
        y.inc_Grade();
        std::cout << t;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}