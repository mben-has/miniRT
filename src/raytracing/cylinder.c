/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:19:40 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/20 21:20:37 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"
#include <stdarg.h>

int	check_cap(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->origin->dim[0] + t * ray->direction->dim[0];
	z = ray->origin->dim[2] + t * ray->direction->dim[2];
	if ((x * x + z * z) <= 1.0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	intersect_caps(t_object *o, t_ray *ray, t_intersections *xs,
		t_garbage_collector *gc)
{
	t_cylinder	*cyl;
	double		t;

	cyl = (*o).cylinder;
	if (fabs(ray->direction->dim[1] - 0) < EPSILON)
	{
		return ;
	}
	t = (cyl->minimum - ray->origin->dim[1]) / ray->direction->dim[1];
	if (check_cap(ray, t))
	{
		(*xs).xs[(*xs).count++] = intersection(t, *o, gc);
	}
	t = (cyl->maximum - ray->origin->dim[1]) / ray->direction->dim[1];
	if (check_cap(ray, t))
	{
		(*xs).xs[(*xs).count++] = intersection(t, *o, gc);
	}
}

int	calculate_t(double *t0, double *t1, t_ray *r, t_intersections *xs)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	temp;

	a = r->direction->dim[0] * r->direction->dim[0] + r->direction->dim[2]
		* r->direction->dim[2];
	b = 2 * (r->origin->dim[0] * r->direction->dim[0] + r->origin->dim[2]
			* r->direction->dim[2]);
	c = r->origin->dim[0] * r->origin->dim[0] + r->origin->dim[2]
		* r->origin->dim[2] - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return ((*xs).count = 0, 0);
	*t0 = (-b - sqrt(disc)) / (2 * a);
	*t1 = (-b + sqrt(disc)) / (2 * a);
	if (*t0 > *t1)
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
	return (1);
}

t_intersections	intersect_cylinder(t_object o, t_ray *r,
		t_garbage_collector *gc)
{
	t_intersections	xs;
	double			y0;
	double			y1;
	double			t0;
	double			t1;

	xs.count = 0;
	if (!calculate_t(&t0, &t1, r, &xs))
	{
		return (xs);
	}
	y0 = r->origin->dim[1] + t0 * r->direction->dim[1];
	if (o.cylinder->minimum < y0 && y0 < o.cylinder->maximum)
	{
		xs.xs[xs.count++] = intersection(t0, o, gc);
	}
	y1 = r->origin->dim[1] + t1 * r->direction->dim[1];
	if (o.cylinder->minimum < y1 && y1 < o.cylinder->maximum)
	{
		xs.xs[xs.count++] = intersection(t1, o, gc);
	}
	intersect_caps(&o, r, &xs, gc);
	return (xs);
}

t_intersection	intersection_cylinder(double t, t_object *object,
		t_garbage_collector *gc)
{
	t_intersection	i;

	i.t = t;
	i.object = (t_object *)malloc(sizeof(t_object));
	if (!i.object)
		exit_function(gc, "error alloc obj\n", 1, true);
	else
		add_pointer_node(gc, i.object);
	i.object->plane = NULL;
	i.object->id = 'c';
	i.object->sphere = NULL;
	i.object->cylinder = (*object).cylinder;
	return (i);
}
