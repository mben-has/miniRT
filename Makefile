NAME = minirt
FLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -Wall -Wextra -g 
# -fsanitize=address
LIBFT = libs/libft/libft.a
MLX = libs/mlx/libmlx42.a 
LINALG = libs/liblinalg/liblinalg.a 
SRC = 	src/main.c \
		src/helper_functions.c \
		src/garbage_collector/exit_function.c \
		src/garbage_collector/free.c \
		src/garbage_collector/garbage_collector.c \
		src/parsing/parsing_main.c \
		src/parsing/check_elements.c \
		src/parsing/parsing_helper.c \
		src/raytracing/raytracing_main.c \
		src/initialization.c 

OBJECTS = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) $(MLX) $(LINALG)
	cc $(DEBUGFLAGS) -Llibs/libft -lft -Llibs/liblinalg -llinalg -lglfw -Llibs/mlx -lmlx42 -lm $(OBJECTS) -o $(NAME)

$(LIBFT) :
	cd libs/libft; make; make clean

$(LINALG) :
	cd libs/liblinalg; make; make clean

$(MLX) :
	cd libs/mlx; git clone https://github.com/codam-coding-college/MLX42.git; \
	cd MLX42; cmake -B build; cmake --build build -j4; \
	cd ..; mv MLX42/build/libmlx42.a .; \
	mv MLX42/include/MLX42/MLX42.h ../../include; \
	rm -rf MLX42

testlib	: $(LINALG)
	cc $(DEBUGFLAGS) -Llibs/liblinalg -llinalg test/testlib.c -o testlib 
	rm -f $(LINALG)

%.o : %.c
	cc $(DEBUGFLAGS) -Iinclude -c $< -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME) $(LINALG)

re : fclean all

bonus :
	
