/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:54 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/21 10:22:04 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Form t("test", true, 100, 100);
        Form d;
        Bureaucrat b(20, "hassan");
        t.beSigned(b);
        //t.beSigned(b);
        b.signForm(t);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}