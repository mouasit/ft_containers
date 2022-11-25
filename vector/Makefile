NAME = vector

SRC =  main.cpp
HEADER = vector_iterator.hpp\
		 vector.hpp\
		  ../utils/reverse_iterator.hpp\
		  ../utils/lexicographical_compare.hpp\
		  ../utils/is_integral.hpp\
		../utils/enable_if.hpp\
		../utils/equal.hpp

all : $(NAME)

$(NAME): $(SRC) $(HEADER)
	@c++  -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)
	
clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all