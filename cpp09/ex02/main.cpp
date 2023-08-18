/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:51:24 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/18 05:55:25 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <deque>
#include <iostream>

// class tazi
// {
//     private:
//         std::vector <int> vi;

// } ;
// u_int64_t	get_time(void)
// {
// 	struct timeval	tv;

// 	if (gettimeofday(&tv, NULL))
// 		return (error("gettimeofday() FAILURE\n", NULL));
// 	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
// }

int parse(char c)
{
    return (c - '0');
}

void    ft_sort(std::vector<int> &v)
{
    for(unsigned int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            int f = v[i];
            v[i] = v[i + 1];
            v[i + 1] = f;
            i = -1;
        }
    }
}

void    sort_vector(std::vector<int> &vi)
{
    std::vector<std::pair<int , int> > vpr;
    int lonly_number;
    if (vi.size()%2)
    {
        lonly_number = vi.back();
        vi.pop_back();
    }
    for(unsigned int i =0; i < vi.size(); i+=2)
    {
        vpr.push_back(std::make_pair(vi[i], vi[i + 1]));
    }

    for(unsigned int i =0; i < vpr.size(); i++)
    {
        if (vpr[i].first > vpr[i].second)
        {
            int f = vpr[i].first;
            vpr[i].first = vpr[i].second;
            vpr[i].second = f;
        }
    }
    //     std::cout << lonly_number << std::endl;
    std::vector<int> sorted_vector;
    std::vector<int> sorted_vector2;
    for(unsigned int i =0; i < vpr.size(); i++)
    {
        sorted_vector.push_back(vpr[i].first);
        sorted_vector2.push_back(vpr[i].second);
    }
    ft_sort(sorted_vector);
    ft_sort(sorted_vector2);
    std::vector<int>::iterator it;
    for(unsigned int i =0; i < sorted_vector.size(); i++)
    {
        it = std::lower_bound(sorted_vector2.begin(), sorted_vector2.end(), sorted_vector[i]);
        sorted_vector2.insert(it, sorted_vector[i]);
    }

    int flag = 0;
    for(unsigned int i =0; i < sorted_vector2.size() - 1; i++)
    {
        if (sorted_vector2[i] > sorted_vector2[i + 1])
            {
                std::cout << "error" << std::endl;
                exit(0);
            }
            if ( i == sorted_vector2.size() - 2)
                flag++;
    }
    for(unsigned int i =0; i < sorted_vector2.size(); i++)
    {
        std::cout << sorted_vector2[i] << " ";
    }
    std::cout << std::endl << flag << std::endl;
}

int main(int ac, char **av)
{
    std::vector<int> vi;
    std::deque<int> di;
    // unsigned long long start = get_time(), end;

    for(int i = 1; i < ac;i++)
    {
        // vi.push_back(parse(av[i + 1]));
        vi.push_back(atoi(av[i]));
    }
    sort_vector(vi);
    // end = get_time();
    // cout << "time spent to sort the first container [vector] :" << end - start << endl;
    // start = get_time();
    // for(int i = 0; i < ac;i++)
    // {
    //     di.push_back(std::atoi(av[i + 1]));
    // }
    //     sort_deque(vi);
    // end = get_time();
    // cout << "time spent /to sort the first container [deque] :" << end - start << endl;
}