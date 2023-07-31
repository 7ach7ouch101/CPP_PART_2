/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:14:59 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/29 23:43:35 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
        std::cout << "INVALID ARGS." << std::endl;
}