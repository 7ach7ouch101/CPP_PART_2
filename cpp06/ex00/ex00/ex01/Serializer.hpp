/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:36:54 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/01 23:48:20 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct Data
{
    float dd;
    char c;
    int a;
}Data;

class Serializer
{
    private:
        Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data*  deserialize(uintptr_t raw);
        Serializer & operator=(const Serializer &serializer);
        ~Serializer();
        Serializer(const Serializer &serializer);
};

#endif