/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:07:05 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/19 11:34:02 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

char is_op(char s)
{
    if((s == '*') || (s == '+') || (s == '-') || (s == '/'))
        return (s);
    return (0);
}

int    RPN::calculate(char op)
{
    int a = 0;
    int b = 0;

    if (stack.size() < 2)
        return (0);
    a = stack.top();
    stack.pop();
    b = stack.top();
    stack.pop();
    if(op == '+')
        stack.push(b + a);
    if(op == '-')
        stack.push(b - a);
    if(op == '/')
    {
        if(a != 0)
            stack.push(b / a);
        else
            return 0;
    }
    if(op == '*')
        stack.push(b * a);
    return (1);
}

int    RPN::rpn(std::string s)
{
    for(size_t i = 0; i < s.length(); i++)
    {
        if (is_op(s[i]))
        {
            if(calculate(is_op(s[i])) == 0)
                return (0);
        }
        else if(isdigit(s[i]))
            this->stack.push(s[i] - 48);
        else if(s[i] == ' ' || s[i] == '\t')
            continue ;
        else
            return (0);
    }
    if (this->stack.size() != 1)
        return 0;
    std::cout << stack.top() << std::endl;
    return (1);
}