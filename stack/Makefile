NAME = stack

SRC =  main.cpp
HEADER = ../vector/vector.hpp

all : $(NAME)

$(NAME): $(SRC) $(HEADER)
	@c++  -Wall -Wextra -Werror -std=c++98  -fsanitize=address -g $(SRC) -o $(NAME)
	
clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all