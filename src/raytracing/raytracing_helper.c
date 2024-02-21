/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:18:02 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:51 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

unsigned int	rgb_to_hex(t_color *col)
{
	int	g;
	int	r;
	int	b;
	int	a;

	a = 255;
	r = (int) floor(col->col[0] * 255);
	g = (int) floor(col->col[1] * 255);
	b = (int) floor(col->col[2] * 255);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

double	length_vector(t_vector *v, t_vector *point, t_garbage_collector *gc)
{
	double	dx;
	double	dy;
	double	dz;

	(void) gc;
	dx = v->dim[0] - point->dim[0];
	dy = v->dim[1] - point->dim[1];
	dz = v->dim[2] - point->dim[2];
	return (sqrt(dx * dx + dy * dy + dz * dz));
}

void	print_matrix(t_matrix *m)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < 4)
	{
		l = 0;
		while (l < 4)
		{
			printf("| %f | ", (*m)[k][l]);
			l++;
		}
		printf("\n");
		k++;
	}
}
