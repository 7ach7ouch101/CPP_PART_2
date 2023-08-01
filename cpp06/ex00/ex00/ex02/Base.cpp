/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 01:51:09 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/01 04:13:39 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << "Destructor Base Called" << std::endl;
}

Base * generate(void)
{
    srand(std::time(0));
    int ran = rand();
    switch(ran % 3)
    {
        case 0:
            return (new A());
            break ;
        case 1:
            return (new B());
            break;
        case 2:
            return (new C());
            break;
    }
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "type is undefined" << std::endl;
    }
}
void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(std::exception &e)
    {
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(std::exception &e)
    {
    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(std::exception &e)
    {
    }
}