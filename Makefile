NAME = minirt
FLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -Wall -Wextra -g -fsanitize=address
SRC = src/main.c src/parsing/parsing_main.c 
OBJECTS = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS)
	cc $(DEBUGFLAGS) $(OBJECTS) -o $(NAME)

%.o : %.c
	cc $(DEBUGFLAGS) -Iinclude -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re :
	fclean all
