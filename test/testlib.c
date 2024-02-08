#include "../libs/liblinalg/liblinalg.h"

#include <stdio.h>

void	test_vector_add()
{
	t_vector v1;
	t_vector v2;
	t_vector *v3;

	v1.dim[0] = 1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;
	v2.dim[0] = 1.0; v2.dim[1] = 2.0; v2.dim[2] = 3.0; v2.dim[3] = 0.0;

	v3 = vector_add(&v1, &v2);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_vector_subtract()
{
	t_vector v1;
	t_vector v2;
	t_vector *v3;

	v1.dim[0] = 1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;
	v2.dim[0] = 2.0; v2.dim[1] = 3.0; v2.dim[2] = 3.5; v2.dim[3] = 0.0;

	v3 = vector_subtract(&v1, &v2);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_vector_negate()
{
	t_vector v1;
	t_vector *v3;

	v1.dim[0] = -1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;

	v3 = vector_negate(&v1);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_scalar_mult()
{
	t_vector v1;
	t_vector *v3;

	v1.dim[0] = -1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;

	v3 = scalar_mult(&v1, 2.5);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_scalar_div()
{
	t_vector v1;
	t_vector *v3;

	v1.dim[0] = -1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;

	v3 = scalar_div(&v1, 2.5);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_magnitude()
{
	t_vector v1;
	double mag;

	v1.dim[0] = -1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;

	mag = magnitude(&v1);
	printf("%f\n", mag);
}

void	test_normalize()
{
	t_vector v1;
	t_vector *v3;
	v1.dim[0] = -1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;

	v3 = normalize(&v1);
	printf("%f %f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3], magnitude(v3));
}

void	test_dot()
{
	t_vector v1;
	t_vector v2;
	double	dotproduct;

	v1.dim[0] = 1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;
	v2.dim[0] = 2.0; v2.dim[1] = 3.0; v2.dim[2] = 3.5; v2.dim[3] = 0.0;

	dotproduct = dot(&v1, &v2);
	printf("%f\n", dotproduct);
}

void	test_cross()
{
	t_vector v1;
	t_vector v2;
	t_vector *v3;

	v1.dim[0] = 1.0; v1.dim[1] = 2.0; v1.dim[2] = 3.0; v1.dim[3] = 0.0;
	v2.dim[0] = 2.0; v2.dim[1] = 3.0; v2.dim[2] = 3.5; v2.dim[3] = 0.0;

	v3 = cross(&v1, &v2);
	printf("%f %f %f %f\n", v3->dim[0], v3->dim[1], v3->dim[2], v3->dim[3]);
}

void	test_color_add()
{
	t_color v1;
	t_color v2;
	t_color *v3;

	v1.col[0] = 0.1; v1.col[1] = 0.2; v1.col[2] = 0.3;
	v2.col[0] = 0.1; v2.col[1] = 0.25; v2.col[2] = 0.0;

	v3 = color_add(&v1, &v2);
	printf("%f %f %f\n", v3->col[0], v3->col[1], v3->col[2]);
}

void	test_color_mult()
{
	t_color v1;
	t_color *v3;

	v1.col[0] = 0.1; v1.col[1] = 0.2; v1.col[2] = 0.3;

	v3 = color_mult(&v1, 2.0);
	printf("%f %f %f\n", v3->col[0], v3->col[1], v3->col[2]);
}

void	test_hadamard_product()
{
	t_color v1;
	t_color v2;
	t_color *v3;

	v1.col[0] = 0.1; v1.col[1] = 0.2; v1.col[2] = 0.3;
	v2.col[0] = 0.1; v2.col[1] = 0.25; v2.col[2] = 0.0;

	v3 = hadamard_product(&v1, &v2);
	printf("%f %f %f\n", v3->col[0], v3->col[1], v3->col[2]);
}

void	test_double_equal()
{
	double a = 0.0001;
	double b = 0.00099;
	int	is_equal;

	is_equal = double_equal(a, b);
	printf("%d\n", is_equal);
}

void	test_matrix_equal()
{
	t_matrix a = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	t_matrix b = {{1.1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	int	is_equal;

	is_equal = matrix_equal(a, b);
	printf("%d\n", is_equal);
}

void	test_identity_matrix()
{
	t_matrix *m;

	m = identity_matrix();
	printf("%f %f %f %f\n", *m[0][0], *m[0][1], *m[0][2], *m[0][3]);
	printf("%f %f %f %f\n", *m[1][0], *m[1][1], *m[1][2], *m[1][3]);
	printf("%f %f %f %f\n", *m[2][0], *m[2][1], *m[2][2], *m[2][3]);
	printf("%f %f %f %f\n", *m[3][0], *m[3][1], *m[3][2], *m[3][3]);
}

void	test_matrix_mult()
{
	t_matrix 	*m;
	t_matrix	*b;
	t_matrix a = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

	b = identity_matrix();
	m = matrix_mult_m(&a, b);
	printf("test\n");
	printf("%f %f %f %f\n", *m[0][0], *m[0][1], *m[0][2], *m[0][3]);
	printf("%f %f %f %f\n", *m[1][0], *m[1][1], *m[1][2], *m[1][3]);
	printf("%f %f %f %f\n", *m[2][0], *m[2][1], *m[2][2], *m[2][3]);
	printf("%f %f %f %f\n", *m[3][0], *m[3][1], *m[3][2], *m[3][3]);

	printf("\n");
}

void	test_transpose()
{
	t_matrix a = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	t_matrix *m;

	m = transpose(a);
	printf("%f %f %f %f\n", *m[0][0], *m[0][1], *m[0][2], *m[0][3]);
	printf("%f %f %f %f\n", *m[1][0], *m[1][1], *m[1][2], *m[1][3]);
	printf("%f %f %f %f\n", *m[2][0], *m[2][1], *m[2][2], *m[2][3]);
	printf("%f %f %f %f\n", *m[3][0], *m[3][1], *m[3][2], *m[3][3]);
}

int	main()
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
}