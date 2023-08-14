/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:15:52 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/14 04:25:31 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int Bitcoin::check_date_and_value(std::string s)
{
    int count = 0;
    size_t y = s.find('-');
    std::string year = s.substr(0, y);
    size_t m = s.find('-', y);
    std::string month = s.substr((m + 1), 2);
    size_t d = s.find('-', (m + 1));
    std::string day = s.substr((d + 1), 2);
    size_t v = s.find(',',d);
    std::string value = s.substr((v + 1), (s.length() - v));
    if(((std::atof(year.c_str()) >= 2009) && (std::atof(year.c_str()) <= 2022))
        && ((std::atof(month.c_str()) >= 1) && (std::atof(month.c_str()) <= 12))
        && ((std::atof(day.c_str()) >= 1) && (std::atof(day.c_str()) <= 31)))
    {
        for(int i = 0; i < value.length(); i++)
        {
            if ((value[0] == '.' || value[(value.length() - 1)] == '.') || (value[i] <= '0' && value[i] >= '9') || (value[0] == '-'))
                return (0);
            if(value[i] == '.')
                count++;
            if(count > 1)
                return (0);
        }
        this->data[year + '-' + month + '-' + day] = std::atof(value.c_str());
        return (1);
    }
    return (0);
}

int Bitcoin::parse_data()
{
    std::ifstream file;
    std::string s;
    file.open("data.csv");
    if(file)
    {
        std::getline(file, s);
        while(std::getline(file, s))
        {
            if(check_date_and_value(s) == 0)
            {
                std::cout << "Error: missing values in data.csv" << std::endl;
                return (0);
            }
        }
        // std::map<std::string, double>::iterator it = data.begin();
        // std::map<std::string, double>::iterator it2 = data.end();
        // while(it != it2)
        // {
        //     std::cout << it->first << " " << it->second << std::endl;
        //     it++;
        // }
    }
    else
        std::cout << "File does not exists" << std::endl;
    file.close();
    return (1);
}

int Bitcoin::check_date_and_value2(std::string s)
{
    int i  = 0;
    int count = 0;
    int number = 0;
    int error = 0;
    size_t y = s.find('-');
    if(y == std::string::npos)
        error++;
    std::string year = s.substr(0, y);
    size_t m = s.find('-', y);
    if(m == std::string::npos)
        error++;
    std::string month = s.substr((m + 1), 2);
    size_t d = s.find('-', (m + 1));
    if(d == std::string::npos)
        error++;
    std::string day = s.substr((d + 1), 2);
    size_t v = s.find('|',d);
     if(v == std::string::npos)
        error++;
    if (!(s[v + 1]))
        error++;
    std::string value = s.substr((v + 2), (s.length() - v));
    std::string in = (year + "-" + month + "-" + day);
    if(error > 0)
        return (std::cout << "Error: bad input => " << in << std::endl, 1);
    if(value.empty())
        return (std::cout << "Error: missing values in input.txt" << std::endl, 0);
    if(((std::atof(year.c_str()) >= 2009) && (std::atof(year.c_str()) <= 2022))
        && ((std::atof(month.c_str()) >= 1) && (std::atof(month.c_str()) <= 12))
        && ((std::atof(day.c_str()) >= 1) && (std::atof(day.c_str()) <= 31)))
    {
        for(int i = 0; i < value.length(); i++)
        {
            if(value[i] == '-')
                return (std::cout << "Error: not a positive number." << std::endl ,1);
            if(value[i] == ' ')
                continue ;
            if(value[i] == '.')
            {
                count++;
                continue ;
            }
            if(count > 1)
                return (std::cout << "Error: multiple dots in input.txt" << std::endl ,1);
            if ((value[0] == '.' || value[(value.length() - 1)] == '.') || ((!(value[i] >= '0' && value[i] <= '9'))))
                return (std::cout << "Error: bad values in input.txt" << std::endl , 1);
            if(value[i] >= 0 && value[i] <= 9)
                number++;
        }
        int test = std::atof(value.c_str());
        if((test < 0 || test > 1000))
            return (std::cout << "Error: too large a number." << std::endl ,1);
        std::map<std::string, double>::iterator it;
        it = data.find(in);
        if(it != data.end())
            std::cout << in << " => " << std::atof(value.c_str()) << " = " << (it->second * std::atof(value.c_str())) << std::endl;
        else
        {
            it = data.lower_bound(in);
            it--;
            std::cout << in << " => " << std::atof(value.c_str()) << " = " << (it->second * std::atof(value.c_str())) << std::endl;
        }
        return (1);
    }
    return (0);
}

int Bitcoin::parse_input()
{
    std::ifstream file;
    std::string s;
    file.open("input.txt");
    if(file)
    {
        std::getline(file, s);
        while(std::getline(file, s))
        {
            while(s.length() == 0)
                std::getline(file, s);
            if(check_date_and_value2(s) == 0)
                return (0);
        }
    }
    else
        std::cout << "File does not exists" << std::endl;
    file.close();
    return (0);
}