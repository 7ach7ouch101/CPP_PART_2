/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:15:01 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/02 00:16:45 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = scalarConverter;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &scalarConverter)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor constructor called" << std::endl;
}

int ScalarConverter::detect_type(std::string s)
{
    //check_char
    if(s.length() == 1 && std::isprint(s[0]) && isdigit(s[0]) == 0)
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
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    ScalarConverter::convert_to_int(std::string s)
{
    double i = std::atof(s.c_str());
    if(std::isprint(i))
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if((i < INT_MIN || i > INT_MAX))
        std::cout << "int: overflow occurus" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
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
    int a = i;
    if(std::isprint(i))
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if((i < INT_MIN || i > INT_MAX))
        std::cout << "int: overflow occurus" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    if (!(i - a))
        std::cout << "float: " << i << ".0f" << std::endl;
    else
        std::cout << "float: " << i << "f" << std::endl;
    if (!(i - a))
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void    ScalarConverter::convert_to_double(std::string s)
{
    double i = std::atof(s.c_str());
    int a = i;
    if(std::isprint(i))
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if((i < INT_MIN || i > INT_MAX))
        std::cout << "int: overflow occurus" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    if (!(i - a))
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    if (!(i - a))
        std::cout << "double: " << i << ".0" << std::endl;
    else
        std::cout << "double: " << i << std::endl;
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