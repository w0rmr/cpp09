Target = PmergeMe

CC = c++

FLAGS =# -fsanitize=address -g #-Wall -Wextra -Werror -std=c++98 -fsanitize=address

FILES = main.cpp PmergeMe.cpp 

objects = $(FILES:.cpp=.o)

$(Target): $(objects)
	$(CC) $(FLAGS) -o $(Target) $(objects)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(objects)

fclean: clean
	rm -f $(Target)

re: fclean $(Target)