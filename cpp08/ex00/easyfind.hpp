/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 03:06:23 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/11 03:06:23 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class NumberNotfound : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Number not found");
		}
};

template <typename T>
int easyfind(T &c, int num)
{
    typename T::iterator it;
    it = find(c.begin(), c.end(), num);
    if(it == c.end())
        throw NumberNotfound();
    else
        return (num);
}

#endif