/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:15:01 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/30 02:37:35 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::detect_type(const std::string s)
{
    //check_char
    if(s.length() == 1 && std::isprint(s[0]) && isalpha(s[0]))
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
    for(int i = 0 ; s[i]; i++)
    {
        int dot = 0;
        if((i == (s.length() - 1) && s[i] == 'f') || isdigit(s[i]) != 0)
        {
            if(s[i + 1] == '\0')
            {
                for(int j = 0; s[j] ; j++)
                {
                    if(isdigit(s[j]) != 0 && s[s.length() - 1] == 'f')
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
    for(int i = 0 ; s[i]; i++)
    {
        int dot = 0;
        if(isdigit(s[i]) != 0)
        {
            if(s[i + 1] == '\0')
            {
                for(int j = 0; s[j] ; j++)
                {
                    if(isdigit(s[j]) != 0)
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
    return (100);
}

void    ScalarConverter::convert(const std::string s)
{
    int index = 0;
    std::string arr[4] = {"char", "int", "float", "double"};
    index = detect_type(s);
    std::cout << index << std::endl;
    // switch ()
    // {
    // case :
    //     break;
    // default:
    //     break;
    // }
}