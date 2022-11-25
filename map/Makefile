NAME = map

SRC =  main.cpp
HEADER = ../utils/pair.hpp\
		 ../utils/avlTree.hpp\
		 iterators.hpp\
		 ../utils/reverse_iterator.hpp\
		 ../utils/node.hpp\
		 ../utils/lexicographical_compare.hpp\
		 ../utils/equal.hpp

all : $(NAME)

$(NAME): $(SRC) $(HEADER)
	@c++  -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)
	
clean:
	@rm -rf $(NAME)

fclean:
	@rm -rf $(NAME)

re: fclean all