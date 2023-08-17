/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:15:57 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/16 21:01:56 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (0);
    }
    Bitcoin b;
    std::string argvv = av[1];
    if(b.parse_data() == 0)
        return (0);
    if(b.parse_input(argvv) == 0)
        return (0);
    return (0);
}