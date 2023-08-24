NAME = btc
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
SRCS = main.cpp BitcoinExchange.cpp
OBJ = $(SRCS:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp BitcoinExchange.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all