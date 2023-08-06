/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:46:41 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/05 23:36:31 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS
#define ARRAY_CLASS

#include <iostream>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int s;
    public:
        Array()
        {
            s = 0;
            arr = new T[0]();
        }
        Array(unsigned int n)
        {
            arr = new T[n]();
            s = n;
        }
        Array(const Array &array)
        {
            std::cout << "copy constructor called." << std::endl;
            s = array.s;
            arr = new T[s]();
            for (unsigned int i = 0; i < s; i++)
                arr[i] = array.arr[i];
        }
        Array &operator=(const Array &array)
        {
            std::cout << "assignation operator called." << std::endl;
            s = array.s;
            arr = new T[s]();
            for (unsigned int i = 0; i < s; i++)
                arr[i] = array.arr[i];
            return (*this);
        }
        ~Array()
        {
            std::cout << "destructor called." << std::endl;
            delete[] arr;
        }
        class IndexException : public std::exception
        {
            const char * what () const throw ()
            {
                return ("Index out of range");
            }
        };
        unsigned int size()
        {
            return (s);
        }
        T &operator[](unsigned int i)
        {
            if (i >= s)
                throw IndexException();
            return (arr[i]);
        }
};


#endif