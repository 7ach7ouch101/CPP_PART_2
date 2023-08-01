NAME = Serialization
src = main.cpp Serializer.cpp
header = Serializer.hpp
flags = -Wall  -Werror -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c) $(flags) $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all