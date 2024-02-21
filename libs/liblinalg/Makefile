NAME = liblinalg.a
FLAGS = -Wall -Wextra -Werror
FUNCTIONS = vector_add.c vector_subtract.c vector_negate.c scalar_mult.c \
			scalar_div.c magnitude.c normalize.c dot.c cross.c \
			color_add.c color_mult.c hadamard_product.c double_equal.c \
			matrix_equal.c identity_matrix.c matrix_mult_m.c row_by_column.c matrix_mult_v.c \
			transpose.c translation.c scaling.c rotation_x.c rotation_y.c \
			rotation_z.c discriminant.c minor.c determinant_3x3.c determinant_4x4.c \
			submatrix.c cofactor.c inverse.c vector.c point.c color.c length_vector.c print_matrix.c

OBJECTS = $(FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar cr $(NAME) $(OBJECTS) 

%.o : %.c
	gcc $(FLAGS) -g -c $<

clean :
	rm -f $(OBJECTS)

fclean: clean 
	rm -f $(NAME)

re: fclean all 