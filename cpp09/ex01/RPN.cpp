/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:07:05 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/16 04:27:33 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parse(std::string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if((s[i] >= '0' && s[i] <= '9') && (s[i + 1] >= '0' && s[i + 1] <= '9') )
            return (0);
        if( (s[i] >= '0' && s[i] <= '9') || (s[i] == '*') 
            || (s[i] == '+') || (s[i] == '-') || (s[i] == '/') || (s[i] == ' ') )
            continue ;
        else
            return (0);
    }
    return (1);
}

int    RPN::rpn(std::string s)
{
    if(parse(s) == 0)
        return (0);
    
    std::string num;
    int number = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            num = s.substr(i, 1);
            number = std::atof(num.c_str());
            this->stack.push(number);
        }
    }
    while(!stack.empty())
    { 
        std::cout << this->stack.top() << std::endl;
        this->stack.pop();
    }
    return (1);
}