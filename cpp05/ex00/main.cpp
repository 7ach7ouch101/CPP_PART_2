/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:54 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/26 23:36:31 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat t(1, "hassan");
        Bureaucrat y(t);
        y.dec_Grade();
        std::cout << y;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    try
    {
        Bureaucrat t(150, "mahmoud");
        t.inc_Grade();
        std::cout << t;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << "----------------------" << std::endl;
    try
    {
        Bureaucrat t(-100, "mahmoud");
        t.inc_Grade();
        std::cout << t;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}