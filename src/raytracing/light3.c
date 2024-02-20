/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:17:42 by marschul          #+#    #+#             */
/*   Updated: 2024/02/20 14:19:48 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

t_matrix	*get_transformation_matrix(t_object *object)
{
	if (object->id == 's')
		return (object->sphere->transformation_matrix);
	if (object->id == 'p')
		return (object->plane->transformation_matrix);
	if (object->id == 'c')
		return (object->cylinder->transformation_matrix);
	return (NULL);
}

t_material	*get_material(t_object *object)
{
	if (object->id == 's')
		return (&object->sphere->material);
	if (object->id == 'p')
		return (&object->plane->material);
	if (object->id == 'c')
		return (&object->cylinder->material);
	return (NULL);
}

t_vector	*compute_point(t_ray *ray, t_intersection *intersection, \
	t_garbage_collector *gc)
{
	t_vector	*vector;

	vector = scalar_mult(ray->direction, intersection->t, gc);
	vector = vector_add(ray->origin, vector, gc);
	return (vector);
}

t_vector	*normal_at(t_object *object, t_matrix *transformation_matrix, \
	t_vector *p, t_garbage_collector *gc)
{
	t_matrix	*inv;
	t_matrix	*transp;
	t_vector	*object_point;
	t_vector	*object_normal;
	t_vector	*world_normal;

	inv = inverse(transformation_matrix, gc);
	object_point = matrix_mult_v(inv, p, gc);
	object_normal = NULL;
	if (object->id == 's')
		object_normal = vector_subtract(object_point, point(0, 0, 0, gc), gc);
	if (object->id == 'p')
		object_normal = vector(0, 1, 0, gc);
	if (object->id == 'c')
		object_normal = get_cylinder_normal(object, object_point, gc);
	transp = transpose(inv, gc);
	world_normal = matrix_mult_v(transp, object_normal, gc);
	world_normal->dim[3] = 0;
	world_normal = normalize(world_normal, gc);
	return (world_normal);
}

t_vector	*reflect(t_vector *in, t_vector *normal, t_garbage_collector *gc)
{
	t_vector	*result;
	double		dot_product;

	result = scalar_mult(normal, 2.0, gc);
	dot_product = dot(in, normal);
	result = scalar_mult(result, dot_product, gc);
	result = vector_subtract(in, result, gc);
	return (result);
}
