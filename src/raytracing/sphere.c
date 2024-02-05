/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:22:44 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/05 13:40:06 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_sphere	*init_sphere(t_vector *position, double diameter, t_vector *color,
		t_garbage_collector *gc)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	else
		add_pointer_node(gc, sphere);
	sphere->point = position;
	sphere->diameter = diameter;
	sphere->radius = diameter * 0.5;
	sphere->color = init_vector(color->coordinate[0], color->coordinate[1],
			color->coordinate[2], gc);
	return (sphere);
}

void setup_sphere(t_sphere **t_sphere)
{
    (*t_sphere)->radius = (*t_sphere)->diameter  * 0.5;
}
double	vector_vector(t_vector *v1, t_vector *v2)
{
	double	a;

	a = v1->coordinate[0] * v2->coordinate[0] + v1->coordinate[1]
		* v2->coordinate[1] + v1->coordinate[2] * v2->coordinate[2];
	return (a);
}

double	hit_sphere(t_sphere *sphere, t_ray *ray, t_garbage_collector *gc)
{
    t_vector *oc;
    double a;
    double b;
    double c;
    double x;
        
	oc = vector_difference(ray->origin, sphere->point, gc);
	a = vector_vector(ray->direction, ray->direction);
	b = 2.0 * vector_vector(oc, ray->direction);
	c = vector_vector(oc, oc) - ((sphere->diameter * 0.5) * (sphere->diameter * 0.5));
	x = b * b - 4 * a * c;

	if (x < 0)
		return (-1.0);
	else
	{
		x = (-b - sqrt(x)) / (2.0 * a);
		return (x);
	}
}
