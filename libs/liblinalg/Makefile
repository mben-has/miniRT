NAME = liblinalg.a
FLAGS = -Wall -Wextra -Werror
FUNCTIONS = vector_add.c 

OBJECTS = $(FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar cr $(NAME) $(OBJECTS) 

%.o : %.c
	gcc $(FLAGS) -c $<

clean :
	rm -f $(OBJECTS)

fclean: clean 
	rm -f $(NAME)

re: fclean all 