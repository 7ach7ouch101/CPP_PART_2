/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:24:21 by mmeziani          #+#    #+#             */
/*   Updated: 2023/07/27 00:53:42 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &obj);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &obj);
        ~PresidentialPardonForm();
        void execute(const Bureaucrat& executor) const;
        class isFormSigned : public std::exception
        {
            public:
                const char* what() const throw();
        };
};