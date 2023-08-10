#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

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
        Span &operator=(const Span &c);
        ~Span();

        void addNumber(int num);
        int shortestSpan();
        int longestSpan( );
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