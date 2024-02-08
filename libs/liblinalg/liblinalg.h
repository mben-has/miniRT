/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblinalg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:19:25 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 20:03:51 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLINALG_H
# define LIBLINALG_H

# include <stdlib.h>
# ifndef __MATH__
# include <math.h>
# endif

# define EPSILON 0.001

typedef	struct s_vector
{
	double	dim[4];
}	t_vector;

typedef struct s_color {
	double	col[3];
} t_color;

typedef	double t_matrix[4][4];

t_vector	*vector(double a, double b, double c);
t_vector	*point(double a, double b, double c);
t_vector	*vector_add(t_vector* a, t_vector* b);
t_vector	*vector_subtract(t_vector *a, t_vector *b);
t_vector	*vector_negate(t_vector *vector);
t_vector	*scalar_mult(t_vector *vector, double c);
t_vector	*scalar_div(t_vector *a, double c);
double		magnitude(t_vector *vector);
t_vector	*normalize(t_vector *vector);
double		dot(t_vector *a, t_vector *b);
t_vector	*cross(t_vector *a, t_vector *b);
t_color		*color_add(t_color *a, t_color *b);
t_color		*color_mult(t_color *a, double c);
t_color		*hadamard_product(t_color *a, t_color *b);
int			double_equal(double a, double b);
int			matrix_equal(t_matrix a, t_matrix b);
t_matrix	*identity_matrix();
t_matrix	*matrix_mult_m(t_matrix *a, t_matrix *b);
t_vector	*matrix_mult_v(t_matrix *m, t_vector *v);
t_matrix	*transpose(t_matrix *m);

t_matrix	*translation(t_vector *point);
t_matrix	*scaling(t_vector *point);
t_matrix	*rotation_x(double radians);
t_matrix	*rotation_y(double radians);
t_matrix	*rotation_z(double radians);
double		discriminant(double a, double b, double c);
double		row_by_column(double row[4], double column[4]);

#endif
