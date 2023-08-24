/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 05:09:04 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/19 11:42:10 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

////////////////////////_ VECTOR _ /////////////////////////////////////

void merge(std::vector<int> &a, std::vector<int> &l, std::vector<int> &r)
{
    int i = 0, j = 0, k = 0;

    int sl = l.size(); 
    int sr = r.size();
    while (i < sl && j < sr)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            k = k + 1;
            i++;
        }
        else
        {
            a[k] = r[j];
            k = k + 1;
            j++;
        }
    }
    while (i < sl)
    {
        a[k] = l[i];
        k = k + 1;
        i++;
    }
    while (j < sr)
    {
        a[k] = r[j];
        k = k + 1;
        j++;
    }
}

void ft_merge_sort(std::vector<int> &a)
{
    int n = a.size();
    if (n < 2)
        return;
    std::vector<int> l;
    std::vector<int> r;
    l.resize((int)(n / 2));
    r.resize(n - (int)(n / 2));
    for (int i = 0 ; i < (int)(n / 2)  ; i++)
    {
        l[i] = a[i];
    }
    for (int i = (int)(n / 2) ; i < n ; i++)
    {
        r[i - (int)(n / 2)] = a[i];
    }
    ft_merge_sort(l);
    ft_merge_sort(r);
    merge(a, l , r);
}

size_t    binary_search(std::vector<int> &v, int n, int start, int end)
{
    int middle = (start + end) / 2;
    while (1)
    {
        middle = (start + end) / 2;
        if (n <= v[start])
            return (start);
        else if (n >= v[end])
            return (end);
        else if (n == v[middle])
            return (middle);
        else if (end - start  <  2)
            return (start + 1);
        else if (n > v[middle])
            start = middle;
        else if (n < v[middle])
            end = middle;
    }
}

void Pmerge::sort_vector(std::vector<int> &vi)
{
    int lonly_number, lonly_flag = 0;
    if (vi.size() % 2)
    {
        lonly_number = vi.back();
        lonly_flag++;
        vi.pop_back();
    }
    for (unsigned int i = 0; i < vi.size(); i += 2)
    {
        vpr.push_back(std::make_pair(vi[i], vi[i + 1]));
    }

    for (unsigned int i = 0; i < vpr.size(); i++)
    {
        if (vpr[i].first > vpr[i].second)
        {
            int f = vpr[i].first;
            vpr[i].first = vpr[i].second;
            vpr[i].second = f;
        }
    }
    std::vector<int> sorted_vector;
    std::vector<int> sorted_vector2;
    for (unsigned int i = 0; i < vpr.size(); i++)
    {
        sorted_vector.push_back(vpr[i].first);
        sorted_vector2.push_back(vpr[i].second);
    }
    ft_merge_sort(sorted_vector);
    ft_merge_sort(sorted_vector2);
    std::vector<int>::iterator it;
    for(unsigned int i =0; i < sorted_vector.size(); i++)
    {
        it = std::lower_bound(sorted_vector2.begin(), sorted_vector2.end(), sorted_vector[i]);
        sorted_vector2.insert(it, sorted_vector[i]);
    }
    if (lonly_flag)
    {
        it = std::lower_bound(sorted_vector2.begin(), sorted_vector2.end(), lonly_number);
        sorted_vector2.insert(it, lonly_number);
    }
    std::cout << "after : ";
    for(size_t i = 0; i < sorted_vector2.size() ; i++)
    {
        std::cout << sorted_vector2[i] << " ";
    }
    std::cout << std::endl;
}

int Pmerge::parse(std::string s)
{
    for(size_t i = 0; i < s.length() ; i++)
    {
        if((s[i] == '+') && (s[i + 1] >= '0' && s[i + 1] <= '9') && !i)
            continue;
        if((s[i] < '0' || s[i] > '9'))
            return (0);
    }
    return (1);
}

////////////////////////_ DQUE _ /////////////////////////////////////

void merge(std::deque<int> &a, std::deque<int> &l, std::deque<int> &r)
{
    int i = 0, j = 0, k = 0;

    int nl = l.size(), nr = r.size();
    while (i < nl && j < nr)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            k = k + 1;
            i++;
        }
        else
        {
            a[k] = r[j];
            k = k + 1;
            j++;
        }
    }
    while (i < nl)
    {
        a[k] = l[i];
        k = k + 1;
        i++;
    }
    while (j < nr)
    {
        a[k] = r[j];
        k = k + 1;
        j++;
    }
}

void ft_merge_sort(std::deque<int> &a)
{
    int n = a.size();
    if (n < 2)
        return;
    std::deque<int> l;
    std::deque<int> r;
    l.resize((int)(n / 2));
    r.resize(n - (int)(n / 2));
    for (int i = 0 ; i < (int)(n / 2)  ; i++)
    {
        l[i] = a[i];        
    }
    for (int i = (int)(n / 2) ; i < n ; i++)
    {
        r[i - (int)(n / 2)] = a[i];        
    }
    ft_merge_sort(l);
    ft_merge_sort(r);
    merge(a, l , r);
}

void Pmerge::sort_deque(std::deque<int> &dq)
{
    int lonly_number, lonly_flag = 0;
    if (dq.size() % 2)
    {
        lonly_number = dq.back();
        lonly_flag++;
        dq.pop_back();
    }
    for (unsigned int i = 0; i < dq.size(); i += 2)
    {
        vdq.push_back(std::make_pair(dq[i], dq[i + 1]));
    }

    for (unsigned int i = 0; i < vdq.size(); i++)
    {
        if (vdq[i].first > vdq[i].second)
        {
            int f = vdq[i].first;
            vdq[i].first = vdq[i].second;
            vdq[i].second = f;
        }
    }
    std::deque<int> sorted_deque;
    std::deque<int> sorted_deque2;
    for (unsigned int i = 0; i < vdq.size(); i++)
    {
        sorted_deque.push_back(vdq[i].first);
        sorted_deque2.push_back(vdq[i].second);
    }
    ft_merge_sort(sorted_deque);
    ft_merge_sort(sorted_deque2);
    std::deque<int>::iterator it;
    for(unsigned int i = 0; i < sorted_deque.size(); i++)
    {
        it = std::lower_bound(sorted_deque2.begin(), sorted_deque2.end(), sorted_deque[i]);
        sorted_deque2.insert(it, sorted_deque[i]);
    }
    if (lonly_flag)
    {
        it = std::lower_bound(sorted_deque2.begin(), sorted_deque2.end(), lonly_number);
        sorted_deque2.insert(it, lonly_number);
    }
    // std::cout << "after : ";
    // for(size_t i = 0; i < sorted_deque2.size() ; i++)
    // {
    //     std::cout << sorted_deque2[i] << " ";
    // }
    // std::cout << std::endl;
}