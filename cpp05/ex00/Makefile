NAME = Bureaucrat
src = main.cpp Bureaucrat.cpp
header = Bureaucrat.hpp
flags = -Wall -Wextra -Werror -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c) $(flags) $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all