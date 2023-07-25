#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"


class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm* makeForm(const std::string& formname, const std::string& target);
        class Fromnotfound : public std::exception
		{
			public:
				const char* what() const throw()
                {
					return "Form not found";
                }
		};
};

#endif