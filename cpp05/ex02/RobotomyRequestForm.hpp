/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:24:25 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 00:17:29 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class AForm;

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &obj);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);
        ~RobotomyRequestForm();
        void execute(const Bureaucrat& executor) const;
        class isFormSigned : public std::exception
        {
            public:
                const char* what() const throw();
        };
};