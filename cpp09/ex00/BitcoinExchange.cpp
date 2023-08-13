/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:15:52 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/13 01:35:41 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int check_dataandvalue(std::string s)
{
    size_t y = s.find('-');
    std::string year = s.substr(0, y);
    size_t m = s.find('-', (y + 1));
    std::string month = s.substr((m + 1), 2);
    size_t d = s.find('-', m);
    std::string day = s.substr((d + 1), 2);
    size_t v = s.find(',',d);
    std::string value = s.substr((v + 1), (s.length() - v));
    double valuee = std::atof(value.c_str());
    
    if(((std::atof(year.c_str()) >= 2009) && (std::atof(year.c_str()) <= 2022))
        && ((std::atof(month.c_str()) >= 1) && (std::atof(month.c_str()) <= 12))
        && ((std::atof(day.c_str()) >= 1) && (std::atof(day.c_str()) <= 31)))
        return (1);
        //&& (isdigit(valuee) != 0))
    return (0);
}

int Bitcoin::parse_data()
{
    std::ifstream data;
    std::string s;
    data.open("data.csv");
    if(data)
    {
        std::getline(data, s);
        while(std::getline(data, s))
        {
            if(check_dataandvalue(s) == 0)
            {
                std::cout << "Error: missing values in data.csv" << std::endl;
                return (0);
            }
        }
    }
    else
        std::cout << "File does not exists" << std::endl;
    data.close();
    return (0);
}