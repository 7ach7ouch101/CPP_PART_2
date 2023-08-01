/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:36:58 by mmeziani          #+#    #+#             */
/*   Updated: 2023/08/01 01:46:06 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data = {0.42, 'M', 42};

    std::cout << &data << std::endl;
    uintptr_t holder = Serializer::serialize(&data);
    std::cout << holder << std::endl;

    Data* holder2 = Serializer::deserialize(holder);
    std::cout << holder2 << std::endl;
    std::cout << holder2->a << " | " << holder2->c << " | " << holder2->dd << std::endl;

    if (holder2 == &data)
	{
        std::cout << "Pointers match" << std::endl;
	}
	else
	{
		std::cout << "Pointers do not match" << std::endl;
	}

	return (0);
}
