/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:23:55 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/21 17:35:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"
#include "../../include/liblinalg.h"

t_ray	*ray(t_vector *origin, t_vector *direction, t_garbage_collector *gc)
{
	t_ray	*aux;

	aux = malloc(sizeof(t_ray));
	if (!aux)
		exit_function(gc, "error while init ray\n", 1, true);
	else
		add_pointer_node(gc, aux);
	aux->direction = direction;
	aux->origin = origin;
	aux->original_length = length_vector(direction, \
		vector(0, 0, 0, gc), gc);
	aux->direction = normalize(aux->direction, gc);
	return (aux);
}

t_vector	*position(t_ray *ray, double t, t_garbage_collector *gc)
{
	t_vector	*position;

	position = scalar_mult(ray->direction, t, gc);
	position = vector_add(ray->origin, position, gc);
	return (position);
}

t_intersection	hit(t_intersections xs, double r_length)
{
	t_intersection	i;
	int				j;
	double			t;

	i.object = NULL;
	j = 0;
	t = INFINITY;
	while (j < xs.count)
	{
		if (xs.xs[j].t >= r_length - EPSILON && xs.xs[j].t <= t)
		{
			t = xs.xs[j].t;
			i = xs.xs[j];
		}
		j++;
	}
	return (i);
}

t_ray	*transform(t_ray *r, t_matrix *m, t_garbage_collector *gc)
{
	t_ray	*r2;

	r2 = ray(point(0, 0, 0, gc), vector(0, 0, 0, gc), gc);
	r2->origin->dim[0] = (*m)[0][0] * r->origin->dim[0] + (*m)[0][1]
		* r->origin->dim[1] + (*m)[0][2] * r->origin->dim[2] + (*m)[0][3];
	r2->origin->dim[1] = (*m)[1][0] * r->origin->dim[0] + (*m)[1][1]
		* r->origin->dim[1] + (*m)[1][2] * r->origin->dim[2] + (*m)[1][3];
	r2->origin->dim[2] = (*m)[2][0] * r->origin->dim[0] + (*m)[2][1]
		* r->origin->dim[1] + (*m)[2][2] * r->origin->dim[2] + (*m)[2][3];
	r2->direction->dim[0] = (*m)[0][0] * r->direction->dim[0] + (*m)[0][1]
		* r->direction->dim[1] + (*m)[0][2] * r->direction->dim[2];
	r2->direction->dim[1] = (*m)[1][0] * r->direction->dim[0] + (*m)[1][1]
		* r->direction->dim[1] + (*m)[1][2] * r->direction->dim[2];
	r2->direction->dim[2] = (*m)[2][0] * r->direction->dim[0] + (*m)[2][1]
		* r->direction->dim[1] + (*m)[2][2] * r->direction->dim[2];
	return (r2);
}

void	set_transform(t_sphere *s, t_matrix *m, t_garbage_collector *gc)
{
	int	i;
	int	j;

	(void)gc;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*s->transformation_matrix)[i][j] = (*m)[i][j];
			j++;
		}
		i++;
	}
}
