/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:51:24 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/19 11:43:30 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    Pmerge p;
    int j = 1;
    while(av[j])
    {
        if(p.parse(av[j]) == 0)
        {
            std::cout << "Error" << std::endl;
            return (0);
        }
        j++;
    }
    if(ac == 2)
    {
        std::cout << av[1] << std::endl;
        return (0);  
    }
    if(ac <= 1)
    {
        std::cout << "Error" << std::endl;
        return (0);
    }
    std::vector<int> vi;
	struct timeval	yahya;
	struct timeval	hachhouch;
    gettimeofday(&hachhouch, NULL);
    for(int i = 1; i < ac;i++)
    {
        
        vi.push_back(std::atoi(av[i]));
    }
    std::cout << "befor : ";
    for(size_t i = 0; i < vi.size() ; i++)
    {
        std::cout << vi[i] << " ";
    }
    std::cout << std::endl;
    p.sort_vector(vi);
    gettimeofday(&yahya, NULL);
    std::cout << "Time to process a range of "<< vi.size() << " elements with std::vector : " <<(yahya.tv_usec - hachhouch.tv_usec) << "us"<<std::endl;
    /////////////////// _ DQUE _ /////////////////////////
    std::deque<int> dq;
	struct timeval	ayoub;
	struct timeval	bsela;
    gettimeofday(&bsela, NULL);
    for(int i = 1; i < ac;i++)
    {
        dq.push_back(std::atoi(av[i]));
    }
    // std::cout << "befor : ";
    // for(size_t i = 0; i < dq.size() ; i++)
    // {
    //     std::cout << dq[i] << " ";
    // }
    // std::cout << std::endl;
    p.sort_deque(dq);
    gettimeofday(&ayoub, NULL);
    std::cout << "Time to process a range of "<< vi.size() << " elements with std::deque : " <<(ayoub.tv_usec - bsela.tv_usec) << "us"<<std::endl;
    return 0;
}