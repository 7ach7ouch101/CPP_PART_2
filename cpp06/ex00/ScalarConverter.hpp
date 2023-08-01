/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:15:04 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/02 00:15:18 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter & operator=(const ScalarConverter &scalarConverter);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &scalarConverter);
        void    static convert(std::string s);
        int static detect_type(std::string s);
        void    static convert_to_char(std::string s);
        void    static convert_to_int(std::string s);
        void    static convert_to_float(std::string s);
        void    static convert_to_double(std::string s);
        void    static convert_infinityF(std::string s);
        void    static convert_infinity(std::string s);
};

#endif