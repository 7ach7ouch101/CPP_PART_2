/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 02:11:39 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/05 23:03:13 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void    swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T a, T b)
{
    if(a == b)
        return (b);
    if(a < b)
        return (a);
    else
        return (b);
}

template<typename T>
T   max(T a, T b)
{
    if(a == b)
        return (b);
    if(a > b)
        return (a);
    else
        return (b);
}

#endif