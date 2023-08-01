NAME = IdentifyT
src = main.cpp Base.cpp
header = base.hpp A.hpp B.hpp C.hpp
flags = -Wall -Werror -std=c++98
c = c++

all: $(NAME)

$(NAME): $(src) $(header)
	$(c) $(flags) $(src) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all