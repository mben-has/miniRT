/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:13:33 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 17:27:32 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

void	prepare_computations_1(t_computation *comp, t_intersection \
	*intersection, t_ray *ray, t_garbage_collector *gc)
{
	t_matrix		*transformation_matrix;

	transformation_matrix = get_transformation_matrix(intersection->object);
	comp->material = get_material(intersection->object);
	comp->point = compute_point(ray, intersection, gc);
	comp->normalv = normal_at(intersection->object, transformation_matrix, \
		comp->point, gc);
	comp->eyev = vector_negate(ray->direction, gc);
	comp->eyev = normalize(comp->eyev, gc);
	if (dot(comp->normalv, comp->eyev) < 0)
		comp->normalv = vector_negate(comp->normalv, gc);
}

void	prepare_computations_2(t_computation *comp, t_light light, \
	t_garbage_collector *gc)
{
	comp->lightv = vector_subtract(light.position, comp->point, gc);
	comp->lightv = normalize(comp->lightv, gc);
	comp->reflectv = reflect(vector_negate(comp->lightv, gc), comp->normalv, \
		gc);
	comp->effective_color = color_mult(comp->material->color, light.intensity, \
		gc);
	comp->light_color = color(light.intensity, light.intensity, \
		light.intensity, gc);
	comp->dot_light_normal = dot(comp->lightv, comp->normalv);
	comp->dot_reflect_eye = dot(comp->reflectv, comp->eyev);
	comp->over_point = compute_over_point(comp->point, comp->normalv, gc);
}

bool	is_shadowed(t_world *world, t_vector *p, t_garbage_collector *gc)
{
	t_vector		*v;
	t_vector		*direction;
	t_ray			*r;
	t_intersection	intersection;
	t_intersections	intersections;

	v = vector_subtract(world->light.position, p, gc);
	direction = normalize(v, gc);
	r = ray(p, direction, gc);
	intersections = intersect_world(world, r, gc);
	intersection = hit(intersections, 0);
	if (intersection.object != NULL && intersection.t < magnitude(v))
		return (true);
	else
		return (false);
}

t_color	*lighting(t_computation *computation, bool shadowed, \
	t_garbage_collector *gc)
{
	t_material	*material;
	t_color		*ambient;
	t_color		*diffuse;
	t_color		*specular;
	t_color		*result;

	material = computation->material;
	ambient = get_ambient(material->ambient, computation, gc);
	if (shadowed)
		return (ambient);
	diffuse = get_diffuse(material->diffuse, computation, gc);
	specular = get_specular(material->specular, computation, gc);
	result = color_add(ambient, diffuse, gc);
	result = color_add(result, specular, gc);
	return (result);
}
