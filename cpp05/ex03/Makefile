NAME = formmake
src = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
header = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp
flags = -Wall -Wextra -Werror -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c)  $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all