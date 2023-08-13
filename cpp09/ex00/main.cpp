/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:15:57 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/12 18:58:51 by mmeziani         ###   ########.fr       */
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
    if(b.parse_data() == 0)
        return (0);
    //parse_input();
    return (0);
}