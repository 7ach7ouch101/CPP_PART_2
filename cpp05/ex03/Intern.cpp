#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
    std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = other;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

AForm* Intern::makeForm(const std::string& formname, const std::string& target)
{
    std::string str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	try
	{
		for(int j = 0; j < 3; j++)
		{
			if (formname == str[j])
			{
				std::cout << "Intern creates " << formname << std::endl;
				switch(j)
				{
					case 0:
						return (new ShrubberyCreationForm(target));
						break;
					case 1:
						return (new RobotomyRequestForm(target));
						break;
					case 2:
						return (new PresidentialPardonForm(target));
						break;
					default:
						break;
				}
			}
		}
		throw Intern::Fromnotfound();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

Intern::~Intern()
{
    std::cout << "Destructor called" << std::endl;
}