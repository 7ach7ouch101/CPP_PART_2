/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:15:01 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/31 05:51:25 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::detect_type(std::string s)
{
    //check_char
    if(s.length() == 1 && std::isprint(s[0]))
        return (0);
    //check_int
    for(int i = 0 ; s[i]; i++)
    {
        if(isdigit(s[i]) != 0)
        {
            if(s[i + 1] == '\0')
                return (1);
            continue ;
        }
        else if(i == 0 && (s[0] == '-' || s[0] == '+'))
            continue ;
        else
            break ;
        
    }
    //check_float
    int dot = 0;
    for(int i = 0 ; s[i]; i++)
    {
        if((i == (s.length() - 1) && s[i] == 'f') || isdigit(s[i]) != 0)
        {
            if(s[i + 1] == '\0')
            {
                for(int j = 0; s[j] ; j++)
                {
                    if(isdigit(s[j]) != 0 && s[s.length() - 1] == 'f' && dot == 1)
                        return (2);
                }
                break ;
            }
            continue ;
        }
        else if(i == 0 && (s[0] == '-' || s[0] == '+'))
            continue ;
        else if(dot == 0 && (s[i] == '.'))
        {
            dot++;
            continue ;
        }
        else
            break ;
    }
    //check_double
    dot = 0;
    for(int i = 0 ; s[i]; i++)
    {
        if(isdigit(s[i]) != 0)
        {
            if(s[i + 1] == '\0')
            {
                for(int j = 0; s[j] ; j++)
                {
                    if(isdigit(s[j]) != 0 && dot == 1)
                        return (3);
                }
                break ;
            }
            continue ;
        }
        else if(i == 0 && (s[0] == '-' || s[0] == '+'))
            continue ;
        else if(dot == 0 && (s[i] == '.'))
        {
            dot++;
            continue ;
        }
        else
            break ;
    }
    if(s == "-inff" || s == "+inff" || s == "nanf")
        return (4);
    if(s == "-inf" || s == "+inf" || s == "nan")
        return (5);
    return (100);
}

void    ScalarConverter::convert_to_char(std::string s)
{
    char c = s[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".f" << std::endl;
}

void    ScalarConverter::convert_to_int(std::string s)
{
    int i = std::atoi(s.c_str());
    if(std::isprint(i))
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if(i <= INT_MIN || ((i == 0) && (s != "0")) || ((i == -1) && (s != "-1")))
        std::cout << "int: overflow occurus" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if( ((i == -1) && (s != "-1")) || ((i == 0) && (s != "0")))
        std::cout << "float: overflow occurus" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    if( ((i == -1) && (s != "-1")) || ((i == 0) && (s != "0")))
        std::cout << "double: overflow occurus" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;

}

int detect_dot(std::string s)
{
    for(int i = 0; s[i]; i++)
    {
        if(s[i] == '.' && s[i + 1] != '0')
            return (1);
        if(s[i] == '.' && s[i + 1] == '0')
        {
            while(s[i])
            {
                if(s[i] != '0')
                    return (4);
                i++;
            }
            return (3);
        }
        if(s[i] == '.' && s[i + 1] == 'f')
            return (2);
    }
    return (0);
}

void    ScalarConverter::convert_to_float(std::string s)
{
    float i = std::atof(s.c_str());
    if(std::isprint(i))
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if(static_cast<int>(i) == INT_MIN)
        std::cout << "int: overflow occurus" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    if(detect_dot(s) == 1)
    {
        if(detect_dot(s) == 2)
            std::cout << "float: " << i << ".0f" << std::endl;
        else if(detect_dot(s) == 3)
            std::cout << "float: " << i << ".0f" << std::endl;
        else if(detect_dot(s) == 4)
            std::cout << "float: " << i << ".0f" << std::endl;
        else
            std::cout << "float: " << i << "f" << std::endl;
    }
    else
        std::cout << "float: " << i << ".0f" << std::endl;
    if(detect_dot(s) == 1)
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    else if(detect_dot(s) == 3)
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void    ScalarConverter::convert_to_double(std::string s)
{
    double i = std::atof(s.c_str());
    if(std::isprint(i))
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if(static_cast<int>(i) == INT_MIN)
        std::cout << "int: overflow occurus" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    if(detect_dot(s) == 1)
    {
        if(detect_dot(s) == 2)
            std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        else if(detect_dot(s) == 3)
            std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    }
    else
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    if(detect_dot(s) == 1)
        std::cout << "double: " << i << std::endl;
    else if(detect_dot(s) == 3)
        std::cout << "double: " << i << ".0" << std::endl;
    else
        std::cout << "double: " << i << ".0" << std::endl;
}

std::string ScalarConverter::skip_spaces(std::string s)
{
    for(int i = 0; s[i] ; i++)
    {
        if(s[i] == ' ' || s[i] == '\t')
            i++;
        else
            return (s.erase(0, i));
    }
    return (s);
}

void     ScalarConverter::convert_infinityF(std::string s)
{
    if(s == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    if(s == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    if(s == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void     ScalarConverter::convert_infinity(std::string s)
{
    if(s == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    if(s == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    if(s == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void    ScalarConverter::convert(std::string s)
{
    int index = 0;

    s = skip_spaces(s);
    index = detect_type(s);
    switch (index)
    {
        case 0:
            convert_to_char(s);
            break ;
        case 1:
            convert_to_int(s);
            break ;
        case 2:
            convert_to_float(s);
            break ;
        case 3:
            convert_to_double(s);
            break ;
        case 4:
            convert_infinityF(s);
            break ;
        case 5:
            convert_infinity(s);
            break ;
        case 100:
            std::cout << "Error : Value is not defined." << std::endl;
        default:
            break;
    }
}