/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:21:46 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/21 17:51:58 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"
#include <stdarg.h>

void	sort_intersections(t_intersections *xs)
{
	int				i;
	int				j;
	t_intersection	temp;

	i = 0;
	while (i < xs->count - 1)
	{
		j = 0;
		while (j < xs->count - i - 1)
		{
			if (xs->xs[j].t > xs->xs[j + 1].t)
			{
				temp = xs->xs[j];
				xs->xs[j] = xs->xs[j + 1];
				xs->xs[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

t_intersections	intersect_world(t_world *world, t_ray *r,
		t_garbage_collector *gc)
{
	int				i;
	t_intersections	xs;
	t_intersections	aux;
	int				j;

	xs.count = 0;
	aux.count = 0;
	i = 0;
	while (i < world->nr_objects)
	{
		aux = intersect(world->objects[i], r, gc);
		if (aux.count > 0)
		{
			j = 0;
			while (j < aux.count)
			{
				xs.xs[xs.count++] = aux.xs[j];
				j++;
			}
		}
		i++;
	}
	sort_intersections(&xs);
	return (xs);
}

t_intersections	intersect(t_object o, t_ray *r, t_garbage_collector *gc)
{
	t_intersections	xs;
	t_ray			*ray_transformed;

	xs.count = 0;
	if (o.id == 's')
	{
		ray_transformed = transform(r, inverse(o.sphere->transformation_matrix,
					gc), gc);
		xs = intersect_sphere(o, ray_transformed, gc);
	}
	else if (o.id == 'c')
	{
		ray_transformed = transform(r, \
			inverse(o.cylinder->transformation_matrix, gc), gc);
		xs = intersect_cylinder(o, ray_transformed, gc);
	}
	else if (o.id == 'p')
	{
		ray_transformed = transform(r, inverse(o.plane->transformation_matrix,
					gc), gc);
		xs = intersect_plane(o, ray_transformed, gc);
	}
	return (xs);
}

t_intersection	intersection(double t, t_object object, t_garbage_collector *gc)
{
	t_intersection	i;

	i.object = NULL;
	if (object.id == 's')
	{
		i = intersection_sphere(t, &object, gc);
	}
	else if (object.id == 'p')
	{
		i = intersection_plane(t, &object, gc);
	}
	else if (object.id == 'c')
	{
		i = intersection_cylinder(t, &object, gc);
	}
	return (i);
}

t_intersections	intersections(t_intersection first, ...)
{
	va_list			args;
	t_intersections	intersections;
	t_intersection	next;

	intersections.count = 1;
	intersections.xs[0] = first;
	va_start(args, first);
	while (1)
	{
		next = va_arg(args, t_intersection);
		if (next.object == NULL)
			break ;
		intersections.xs[intersections.count] = next;
		intersections.count++;
	}
	va_end(args);
	return (intersections);
}
