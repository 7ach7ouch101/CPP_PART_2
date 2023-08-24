/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 05:09:02 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/19 11:43:43 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>

class Pmerge
{
    private:
        std::vector<std::pair<int, int> > vpr;
        std::deque<std::pair<int, int> > vdq;
    public:
        int parse(std::string s);
        void sort_vector(std::vector<int> &vi);
        void sort_deque(std::deque<int> &vi);
};

#endif