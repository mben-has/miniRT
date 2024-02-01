NAME = minirt
FLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT = libs/libft/libft.a
MLX = libs/mlx/libmlx42.a 
SRC = src/main.c src/helper_functions.c src/parsing/parsing_main.c  src/raytracing/raytracing_main.c \
		src/parsing/check_elements.c 
OBJECTS = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(MLX)
	cc $(DEBUGFLAGS) -Llibs/libft -lft -lglfw -Llibs/mlx -lmlx42 -lm $(OBJECTS) -o $(NAME)

$(LIBFT) :
	cd libs/libft; make; make clean

$(MLX) :
	cd libs/mlx; git clone https://github.com/codam-coding-college/MLX42.git; \
	cd MLX42; cmake -B build; cmake --build build -j4; \
	cd ..; mv MLX42/build/libmlx42.a .; \
	mv MLX42/include/MLX42/MLX42.h ../../include; \
	rm -rf MLX42

%.o : %.c
	cc $(DEBUGFLAGS) -Iinclude -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re :
	fclean all

bonus :
	
