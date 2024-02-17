/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblinalg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:19:25 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:12:20 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLINALG_H
# define LIBLINALG_H

# include <stdlib.h>
# include "../../include/garbage_collector.h"
# ifndef __MATH__
#  include <math.h>
# endif

# define EPSILON 0.001

typedef struct s_vector
{
	double	dim[4];
}	t_vector;

typedef struct s_color {
	double	col[3];
}	t_color;

typedef double	t_matrix[4][4];

t_vector	*vector(double a, double b, double c, t_garbage_collector *gc);
t_vector	*point(double a, double b, double c, t_garbage_collector *gc);
t_color		*color(double a, double b, double c, t_garbage_collector *gc);
t_vector	*vector_add(t_vector *a, t_vector *b, t_garbage_collector *gc);
t_vector	*vector_subtract(t_vector *a, t_vector *b, t_garbage_collector *gc);
t_vector	*vector_negate(t_vector *vector, t_garbage_collector *gc);
t_vector	*scalar_mult(t_vector *vector, double c, t_garbage_collector *gc);
t_vector	*scalar_div(t_vector *a, double c, t_garbage_collector *gc);
double		magnitude(t_vector *vector);
t_vector	*normalize(t_vector *vector, t_garbage_collector *gc);
double		dot(t_vector *a, t_vector *b);
t_vector	*cross(t_vector *a, t_vector *b, t_garbage_collector *gc);
t_color		*color_add(t_color *a, t_color *b, t_garbage_collector *gc);
t_color		*color_mult(t_color *a, double c, t_garbage_collector *gc);
t_color		*hadamard_product(t_color *a, t_color *b, t_garbage_collector *gc);
int			double_equal(double a, double b);
int			matrix_equal(t_matrix a, t_matrix b);
t_matrix	*identity_matrix(t_garbage_collector *gc);
t_matrix	*matrix_mult_m(t_matrix *a, t_matrix *b, t_garbage_collector *gc);
t_vector	*matrix_mult_v(t_matrix *m, t_vector *v, t_garbage_collector *gc);
t_matrix	*transpose(t_matrix *m, t_garbage_collector *gc);
t_matrix	*submatrix(t_matrix *m, int x, int y, t_garbage_collector *gc);
double		cofactor(t_matrix *m, int i, int j, t_garbage_collector *gc);
double		minor(t_matrix *m, int i, int j, t_garbage_collector *gc);
double		determinant_3x3(t_matrix *m);
double		determinant_4x4(t_matrix *m, t_garbage_collector *gc);
t_matrix	*inverse(t_matrix *m, t_garbage_collector *gc);
t_matrix	*translation(t_vector *point, t_garbage_collector *gc);
t_matrix	*scaling(t_vector *point, t_garbage_collector *gc);
t_matrix	*rotation_x(double radians, t_garbage_collector *gc);
t_matrix	*rotation_y(double radians, t_garbage_collector *gc);
t_matrix	*rotation_z(double radians, t_garbage_collector *gc);
double		discriminant(double a, double b, double c);
double		row_by_column(double row[4], double column[4]);

#endif
