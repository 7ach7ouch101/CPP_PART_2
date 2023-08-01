/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:36:56 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/02 00:17:54 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(const Serializer &serializer)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = serializer;
}

Serializer & Serializer::operator=(const Serializer &serializer)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Destructor constructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}