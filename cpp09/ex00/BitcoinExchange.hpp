/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:15:55 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/13 20:47:15 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Bitcoin
{
    private:
        std::map<std::string, double>data;
        std::map<std::string, double>input;
    public:
        int parse_data();
        int parse_input();
        int check_date_and_value(std::string s);
        int check_date_and_value2(std::string s);
};

#endif