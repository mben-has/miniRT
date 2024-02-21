NAME = miniRT
BONUS = miniRT_bonus
FLAGS = 
DEBUGFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT = libs/libft/libft.a
MLX = libs/mlx/libmlx42.a 
LINALG = libs/liblinalg/liblinalg.a 
SRC = 	src/main.c \
		src/helper_functions.c \
		src/garbage_collector/exit_function.c \
		src/garbage_collector/free.c \
		src/garbage_collector/garbage_collector.c \
		src/parsing/parsing_main1.c \
		src/parsing/parsing_main2.c \
		src/parsing/check_elements1.c \
		src/parsing/check_elements2.c \
		src/parsing/parsing_helper1.c \
		src/parsing/parsing_helper2.c \
		src/raytracing/raytracing_main.c \
		src/initialization/init_camera.c \
		src/initialization/init_cylinder.c \
		src/initialization/init_helpers.c \
		src/initialization/init_plane.c \
		src/initialization/init_sphere.c \
		src/initialization/initialization.c \
		src/raytracing/light1.c \
		src/raytracing/light2.c \
		src/raytracing/light3.c \
		src/raytracing/light4.c \
		src/raytracing/ray.c \
		src/raytracing/cylinder.c \
		src/raytracing/intersection.c \
		src/raytracing/plane.c \
		src/raytracing/sphere.c \
		src/raytracing/raytracing_helper.c 
BONUSSRC = src/main.c \
		src/helper_functions.c \
		src/garbage_collector/exit_function.c \
		src/garbage_collector/free.c \
		src/garbage_collector/garbage_collector.c \
		src/parsing/parsing_main1.c \
		src/parsing/parsing_main2.c \
		src/parsing/check_elements1.c \
		src/parsing/check_elements2.c \
		src/parsing/parsing_helper1.c \
		src/parsing/parsing_helper2.c \
		src/raytracing/raytracing_main.c \
		src/initialization/init_camera.c \
		src/initialization/init_cylinder.c \
		src/initialization/init_helpers.c \
		src/initialization/init_plane.c \
		src/initialization/init_sphere.c \
		src/initialization/initialization.c \
		src/raytracing/light1.c \
		src/raytracing/light2_bonus.c \
		src/raytracing/light3.c \
		src/raytracing/light4.c \
		src/raytracing/ray.c \
		src/raytracing/cylinder.c \
		src/raytracing/intersection.c \
		src/raytracing/plane.c \
		src/raytracing/sphere.c \
		src/raytracing/raytracing_helper.c 
OBJECTS = $(SRC:.c=.o)
BONUSOBJECTS = $(BONUSSRC:.c=.o)



all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(LINALG) $(OBJECTS)
	cc $(FLAGS) -Llibs/libft -lft -Llibs/liblinalg -llinalg -lglfw -Llibs/mlx -lmlx42 -lm $(OBJECTS) -o $(NAME)

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
	cc $(FLAGS) -Iinclude -c $< -o $@

clean :
	rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

bonus : $(BONUSOBJECTS) $(LIBFT) $(MLX) $(LINALG)
	cc $(FLAGS) -Llibs/libft -lft -Llibs/liblinalg -llinalg -lglfw -Llibs/mlx -lmlx42 -lm $(BONUSOBJECTS) -o $(BONUS)
