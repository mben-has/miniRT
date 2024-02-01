NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FUNCTIONS1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c   
FUNCTIONS2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
GNL = get_next_line.c get_next_line_utils.c 
OBJECTS1 = $(FUNCTIONS1:.c=.o)
OBJECTS2 = $(FUNCTIONS2:.c=.o)
OBJECTSBONUS = $(BONUS:.c=.o)
OBJECTSGNL = $(GNL:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS1) $(OBJECTS2) $(OBJECTSBONUS) $(OBJECTSGNL)
	ar cr $(NAME) $(OBJECTS1) $(OBJECTS2) $(OBJECTSBONUS) $(OBJECTSGNL)

%.o : %.c
	gcc $(FLAGS) -c $<

clean :
	rm -f $(OBJECTS1) $(OBJECTS2) $(OBJECTSBONUS) $(OBJECTSGNL)

fclean: clean 
	rm -f $(NAME)

re: fclean all 