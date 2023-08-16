/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:07:02 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/16 04:24:07 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        std::string s = av[1];
        RPN n;
        if(n.rpn(s) == 0)
            return (std::cout << "Error" << std::endl, 0);
    }
    else
        std::cout << "args are wrong." << std::endl;
    return (0);
}