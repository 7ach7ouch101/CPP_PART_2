NAME = Stackk
src = main.cpp
header = MutantStack.hpp
flags = -Wall -Werror -Wextra -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c) $(flags) $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all