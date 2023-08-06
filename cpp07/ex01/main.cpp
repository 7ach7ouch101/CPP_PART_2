/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 07:59:59 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/06 12:15:37 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome a;
  Awesome b;
    b = a;
    
  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}