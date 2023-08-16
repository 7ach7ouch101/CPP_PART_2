NAME = RPN
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
SRCS = RPN.cpp main.cpp
OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ) RPN.hpp
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all