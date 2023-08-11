/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:31:09 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/11 01:31:09 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <cmath>

class Span
{
    private:
        std::vector<int> v;
        unsigned int index;
        unsigned int s;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &c);
        Span &operator=(const Span &span);
        ~Span();

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        void addNumbers(std::vector<int>::iterator it, std::vector<int>::iterator it2);

        class FULL: public std::exception
        {
            const char* what() const throw();
        };
        class Nospancanbefound: public std::exception
        {
            const char* what() const throw();
        };
};

#endif