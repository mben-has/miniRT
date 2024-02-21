/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:21:42 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 15:24:25 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

t_vector	*compute_over_point(t_vector *p, t_vector *normalv, \
	t_garbage_collector *gc)
{
	t_vector	*result;

	result = scalar_mult(normalv, EPSILON, gc);
	result = vector_add(result, p, gc);
	return (result);
}

t_color	*get_ambient(t_color *ambient, t_computation *computation, \
	t_garbage_collector *gc)
{
	t_color	*result;

	result = hadamard_product(computation->effective_color, ambient, gc);
	return (result);
}

t_color	*get_diffuse(double diffuse, t_computation *computation, \
	t_garbage_collector *gc)
{
	t_color	*result;

	if (computation->dot_light_normal < 0)
		result = get_black(gc);
	else
		result = color_mult(computation->effective_color, diffuse \
			* computation->dot_light_normal, gc);
	return (result);
}

t_color	*get_specular(double specular, t_computation *computation, \
	t_garbage_collector *gc)
{
	t_color	*result;
	double	factor;

	if (computation->dot_light_normal < 0)
		result = get_black(gc);
	else
	{
		if (computation->dot_reflect_eye <= 0)
			result = get_black(gc);
		else
		{
			factor = pow(computation->dot_reflect_eye, \
				computation->material->shininess);
			result = color_mult(computation->light_color, specular * factor, \
				gc);
		}
	}
	return (result);
}

t_vector	*get_cylinder_normal(t_object *object, t_vector *p, \
	t_garbage_collector *gc)
{
	double		dist;
	t_vector	*object_normal;

	dist = pow(p->dim[0], 2) + pow(p->dim[2], 2);
	if (dist < 1 && p->dim[1] >= object->cylinder->maximum - EPSILON)
		object_normal = vector(0, 1, 0, gc);
	else if (dist < 1 && p->dim[1] <= object->cylinder->minimum + EPSILON)
		object_normal = vector(0, -1, 0, gc);
	else
		object_normal = vector(p->dim[0], 0, p->dim[2], gc);
	return (object_normal);
}
