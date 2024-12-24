Target = PmergeMe

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

FILES = main.cpp

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