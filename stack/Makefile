NAME = stack

SRC =  main.cpp
HEADER = stack.hpp\
		 ../vector/vector.hpp

all : $(NAME)

$(NAME): $(SRC) $(HEADER)
	@c++  -Wall -Wextra -Werror -std=c++98  $(SRC) -o $(NAME)
	
clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all