NAME = Bureaucrat
src = main.cpp Bureaucrat.cpp Form.cpp
header = Bureaucrat.hpp Form.hpp
flags = -Wall -Wextra -Werror -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c)  $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all