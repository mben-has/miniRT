/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:48:44 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/20 23:49:04 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/liblinalg/liblinalg.h"
#include <stdio.h>

void	test_vector_add(void)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	*v3;

	v1.dim[0] = 1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v2.dim[0] = 1.0;
	v2.dim[1] = 2.0;
	v2.dim[2] = 3.0;
	v2.dim[3] = 0.0;
	v3 = vector_add(&v1, &v2);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_vector_subtract(void)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	*v3;

	v1.dim[0] = 1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v2.dim[0] = 2.0;
	v2.dim[1] = 3.0;
	v2.dim[2] = 3.5;
	v2.dim[3] = 0.0;
	v3 = vector_subtract(&v1, &v2);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_vector_negate(void)
{
	t_vector	v1;
	t_vector	*v3;

	v1.dim[0] = -1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v3 = vector_negate(&v1);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_scalar_mult(void)
{
	t_vector	v1;
	t_vector	*v3;

	v1.dim[0] = -1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v3 = scalar_mult(&v1, 2.5);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_scalar_div(void)
{
	t_vector	v1;
	t_vector	*v3;

	v1.dim[0] = -1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v3 = scalar_div(&v1, 2.5);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_magnitude(void)
{
	t_vector	v1;
	double		mag;

	v1.dim[0] = -1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	mag = magnitude(&v1);
	printf("%f\n", mag);
}

void	test_normalize(void)
{
	t_vector	v1;
	t_vector	*v3;

	v1.dim[0] = -1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v3 = normalize(&v1);
	printf("%f %f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3],
			magnitude(v3));
}

void	test_dot(void)
{
	t_vector	v1;
	t_vector	v2;
	double		dotproduct;

	v1.dim[0] = 1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v2.dim[0] = 2.0;
	v2.dim[1] = 3.0;
	v2.dim[2] = 3.5;
	v2.dim[3] = 0.0;
	dotproduct = dot(&v1, &v2);
	printf("%f\n", dotproduct);
}

void	test_cross(void)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	*v3;

	v1.dim[0] = 1.0;
	v1.dim[1] = 2.0;
	v1.dim[2] = 3.0;
	v1.dim[3] = 0.0;
	v2.dim[0] = 2.0;
	v2.dim[1] = 3.0;
	v2.dim[2] = 3.5;
	v2.dim[3] = 0.0;
	v3 = cross(&v1, &v2);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_color_add(void)
{
	t_color	v1;
	t_color	v2;
	t_color	*v3;

	v1.col[0] = 0.1;
	v1.col[1] = 0.2;
	v1.col[2] = 0.3;
	v2.col[0] = 0.1;
	v2.col[1] = 0.25;
	v2.col[2] = 0.0;
	v3 = color_add(&v1, &v2);
	printf("%f %f %f\n", v3->col[0], v3->col[1], v3->col[2]);
}

void	test_color_mult(void)
{
	t_color	v1;
	t_color	*v3;

	v1.col[0] = 0.1;
	v1.col[1] = 0.2;
	v1.col[2] = 0.3;
	v3 = color_mult(&v1, 2.0);
	printf("%f %f %f\n", v3->col[0], v3->col[1], v3->col[2]);
}

void	test_hadamard_product(void)
{
	t_color	v1;
	t_color	v2;
	t_color	*v3;

	v1.col[0] = 0.1;
	v1.col[1] = 0.2;
	v1.col[2] = 0.3;
	v2.col[0] = 0.1;
	v2.col[1] = 0.25;
	v2.col[2] = 0.0;
	v3 = hadamard_product(&v1, &v2);
	printf("%f %f %f\n", v3->col[0], v3->col[1], v3->col[2]);
}

void	test_double_equal(void)
{
	double	a;
	double	b;
	int		is_equal;

	a = 0.0001;
	b = 0.00099;
	is_equal = double_equal(a, b);
	printf("%d\n", is_equal);
}

void	test_matrix_equal(void)
{
	t_matrix	a;
	t_matrix	b;
	int			is_equal;

	a = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	b = {{1.1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	is_equal = matrix_equal(a, b);
	printf("%d\n", is_equal);
}

void	test_identity_matrix(void)
{
	t_matrix	*m;

	m = (t_matrix *)identity_matrix();
	printf("%f %f %f %f\n", (*m)[0][0], (*m)[0][1], (*m)[0][2], (*m)[0][3]);
	printf("%f %f %f %f\n", (*m)[1][0], (*m)[1][1], (*m)[1][2], (*m)[1][3]);
	printf("%f %f %f %f\n", (*m)[2][0], (*m)[2][1], (*m)[2][2], (*m)[2][3]);
	printf("%f %f %f %f\n", (*m)[3][0], (*m)[3][1], (*m)[3][2], (*m)[3][3]);
}

void	test_matrix_mult(void)
{
	t_matrix	*m;
	t_matrix	*b;
	t_matrix	a;

	a = {{1.1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	b = identity_matrix();
	m = matrix_mult_m(&a, b);
	printf("%f %f %f %f\n", (*m)[0][0], (*m)[0][1], (*m)[0][2], (*m)[0][3]);
	printf("%f %f %f %f\n", (*m)[1][0], (*m)[1][1], (*m)[1][2], (*m)[1][3]);
	printf("%f %f %f %f\n", (*m)[2][0], (*m)[2][1], (*m)[2][2], (*m)[2][3]);
	printf("%f %f %f %f\n", (*m)[3][0], (*m)[3][1], (*m)[3][2], (*m)[3][3]);
	printf("\n");
}

void	test_transpose(void)
{
	t_matrix	a;
	t_matrix	*m;

	a = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	m = transpose(&a);
	printf("%f %f %f %f\n", (*m)[0][0], (*m)[0][1], (*m)[0][2], (*m)[0][3]);
	printf("%f %f %f %f\n", (*m)[1][0], (*m)[1][1], (*m)[1][2], (*m)[1][3]);
	printf("%f %f %f %f\n", (*m)[2][0], (*m)[2][1], (*m)[2][2], (*m)[2][3]);
	printf("%f %f %f %f\n", (*m)[3][0], (*m)[3][1], (*m)[3][2], (*m)[3][3]);
	printf("\n");
}

void	test_translation(void)
{
	t_vector	p;
	t_vector	p2;
	t_vector	*result;
	t_matrix	*m;

	p = {5, -3, 2, 1};
	p2 = {-3, 4, 5, 1};
	m = translation(&p);
	result = matrix_mult_v(m, &p2);
	printf("%f %f %f\n", result->dim[0], result->dim[1], result->dim[2]);
	printf("\n");
}

void	test_scaling(void)
{
	t_vector	p;
	t_vector	p2;
	t_vector	*result;
	t_matrix	*m;

	p = {2, 3, 4, 0};
	p2 = {-4, 6, 8, 1};
	m = scaling(&p);
	result = matrix_mult_v(m, &p2);
	printf("%f %f %f\n", result->dim[0], result->dim[1], result->dim[2]);
	printf("\n");
}

void	test_rotation_x(void)
{
	t_vector	p;
	t_vector	*result;
	t_matrix	*m;

	p = {0, 1, 0, 0};
	m = rotation_x(M_PI / 2);
	result = matrix_mult_v(m, &p);
	printf("%f %f %f\n", result->dim[0], result->dim[1], result->dim[2]);
	printf("\n");
}

void	test_inverse(void)
{
	t_matrix	a;
	t_matrix	*m;

	a = {{-5, 2, 6, -8}, {1, -5, 1, 8}, {7, 7, -6, -7}, {1, -3, 7, 4}};
	m = inverse(&a);
	printf("Test Inverse\n");
	printf("Determinant %f\n", determinant_4x4(&a));
	printf("Cofactor %f\n", cofactor(&a, 3, 2));
	printf("%f %f %f %f\n", (*m)[0][0], (*m)[0][1], (*m)[0][2], (*m)[0][3]);
	printf("%f %f %f %f\n", (*m)[1][0], (*m)[1][1], (*m)[1][2], (*m)[1][3]);
	printf("%f %f %f %f\n", (*m)[2][0], (*m)[2][1], (*m)[2][2], (*m)[2][3]);
	printf("%f %f %f %f\n", (*m)[3][0], (*m)[3][1], (*m)[3][2], (*m)[3][3]);
	printf("\n");
}

int	main(void)
{
	test_vector_add();
	test_vector_subtract();
	test_vector_negate();
	test_scalar_mult();
	test_scalar_div();
	test_magnitude();
	test_normalize();
	test_dot();
	test_cross();
	test_color_add();
	test_color_mult();
	test_hadamard_product();
	test_double_equal();
	test_matrix_equal();
	test_identity_matrix();
	test_matrix_mult();
	test_transpose();
	test_translation();
	test_scaling();
	test_rotation_x();
	test_inverse();
}