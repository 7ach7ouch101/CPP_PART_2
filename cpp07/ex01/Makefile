NAME = Iter
src = main.cpp
header = iter.hpp
flags = -Wall -Werror -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c) $(flags) $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all