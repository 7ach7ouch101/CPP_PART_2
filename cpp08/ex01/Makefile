NAME = Span
src = main.cpp Span.cpp
header = Span.hpp
flags = -Wall -Werror -Wextra -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c) $(flags) $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all