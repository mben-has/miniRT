/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:18:22 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/20 21:39:31 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"
#include <stdarg.h>

double	calculate_discriminant(double *t1, double *t2, t_ray *r2,
		t_vector *sphere_to_ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = dot(r2->direction, r2->direction);
	b = 2 * dot(r2->direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
	{
		return (0);
	}
	*t1 = (-b - sqrt(discriminant)) / (2 * a);
	*t2 = (-b + sqrt(discriminant)) / (2 * a);
	return (1);
}

t_intersections	intersect_sphere(t_object o, t_ray *r2, t_garbage_collector *gc)
{
	t_intersections	xs;
	t_vector		*sphere_to_ray;
	double			t1;
	double			t2;

	xs.count = 0;
	sphere_to_ray = vector_subtract(r2->origin, point(0, 0, 0, gc), gc);
	if (!calculate_discriminant(&t1, &t2, r2, sphere_to_ray))
	{
		xs.count = 0;
		return (xs);
	}
	xs = intersections(intersection(t1, o, gc), intersection(t2, o, gc), NULL);
	return (xs);
}

t_intersection	intersection_sphere(double t, t_object *object,
		t_garbage_collector *gc)
{
	t_intersection	i;

	i.t = t;
	i.object = (t_object *)malloc(sizeof(t_object));
	if (!i.object)
		exit_function(gc, "error alloc obj\n", 1, true);
	else
		add_pointer_node(gc, i.object);
	i.object->sphere = (*object).sphere;
	i.object->id = 's';
	i.object->plane = NULL;
	i.object->cylinder = NULL;
	return (i);
}
