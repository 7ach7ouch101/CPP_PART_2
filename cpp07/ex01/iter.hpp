/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 08:00:02 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/06 12:15:31 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

class Awesome
{
  public:
    int a= 5;
  private:
    int _n;
};

template<typename T>
void    func(T const &array)
{
    std::cout << array;
}

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T const &x )
{
  std::cout << x << std::endl;
  return;
}

template<typename T>
void    iter(T* array, int len, void (*print)(T const &arry))
{
    for(int i = 0; i < len; i++)
        print(array[i]);
}


#endif