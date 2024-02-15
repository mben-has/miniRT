/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:07:59 by marschul          #+#    #+#             */
/*   Updated: 2024/02/15 07:58:34 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

t_color	*get_black(t_garbage_collector *gc)
{
	t_color	*col;

	col = color(0.0, 0.0, 0.0, gc);
	return (col);
}

t_color	*get_ambient(double ambient, t_computation *computation, t_garbage_collector *gc)
{
	t_color	*result;

	result = color_mult(computation->effective_color, ambient, gc);
	return (result);
}

t_color	*get_diffuse(double diffuse, t_computation *computation, t_garbage_collector *gc)
{
	t_color	*result;

	if (computation->dot_light_normal < 0)
		result = get_black(gc);
	else
		result = color_mult(computation->effective_color, diffuse * computation->dot_light_normal, gc);
	return (result);
}

t_color	*get_specular(double specular, t_computation *computation, t_garbage_collector *gc)
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
			factor = pow(computation->dot_reflect_eye, computation->material->shininess);
			result = color_mult(computation->light_color, specular * factor, gc);
		}
	}
	return (result);
}

t_color *lighting(t_computation *computation, bool shadowed, t_garbage_collector *gc)
{
	t_material	*material;
	t_color	*ambient;
	t_color	*diffuse;
	t_color	*specular;
	t_color	*result;

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

t_matrix	*get_transformation_matrix(t_object *object)
{
	if (object->id == 's')
		return object->sphere->transformation_matrix;
	if (object->id == 'p')
		return object->plane->transformation_matrix;
	if (object->id == 'c')
		return object->cylinder->transformation_matrix;
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

t_vector	*compute_point(t_ray *ray, t_intersection *intersection, t_garbage_collector *gc)
{
	t_vector	*vector;

	vector = scalar_mult(ray->direction, intersection->t, gc);
	vector = vector_add(ray->origin, vector, gc);
	return (vector);
}

t_vector	*normal_at(t_matrix *transformation_matrix, t_vector *p, char id, t_garbage_collector *gc)
{
	t_matrix	*inv;
	t_matrix	*transp;
	t_vector	*object_point;
	t_vector	*object_normal;
	t_vector	*world_normal;

	assert(transformation_matrix != NULL);
	inv = inverse(transformation_matrix, gc);
	object_point = matrix_mult_v(inv, p, gc);
	object_normal = NULL;
	if (id == 's')
		object_normal = vector_subtract(object_point, point(0, 0, 0, gc), gc);
	if (id == 'p')
		object_normal = vector(0.0, 1.0, 0.0, gc);
	assert(object_normal != NULL);
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

t_vector	*compute_over_point(t_vector* p, t_vector *normalv, t_garbage_collector *gc)
{
	t_vector *result;

	result = scalar_mult(normalv, EPSILON, gc);
	result = vector_add(result, p, gc);
	return (result);
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
	{
		return (true);
	}
	else
		return (false);
}

t_computation	*prepare_computations(t_intersection *intersection, t_ray *ray, t_light light, t_garbage_collector *gc)
{
	t_computation	*comp;
	t_matrix		*transformation_matrix;

	comp = (t_computation *) malloc(sizeof(t_computation));
	if (comp == NULL)
		exit_function(gc, "malloc fail\n", 1, true);
	else
		add_pointer_node(gc, comp);
	transformation_matrix = get_transformation_matrix(intersection->object);
	comp->material = get_material(intersection->object);
	comp->point	= compute_point(ray, intersection, gc);
	comp->lightv = vector_subtract(light.position, comp->point, gc);
	comp->lightv = normalize(comp->lightv, gc);
	comp->normalv = normal_at(transformation_matrix, comp->point, intersection->object->id, gc);
	comp->eyev = vector_negate(ray->direction, gc);
	comp->eyev = normalize(comp->eyev, gc);
	comp->reflectv = reflect(vector_negate(comp->lightv, gc), comp->normalv, gc);
	comp->effective_color = color_mult(comp->material->color, light.intensity, gc);
	comp->light_color = color(light.intensity, light.intensity, light.intensity, gc);
	comp->dot_light_normal = dot(comp->lightv, comp->normalv);
	comp->dot_reflect_eye = dot(comp->reflectv, comp->eyev);
	comp->over_point = compute_over_point(comp->point, comp->normalv, gc);
	return (comp);
}

t_color	*shade_hit(t_world *world, t_computation *computation, t_garbage_collector *gc)
{	
	bool	shadowed;

	shadowed = is_shadowed(world, computation->point, gc);
	return lighting(computation, shadowed, gc);
}

t_color	*color_at(t_world *world, t_ray *ray, t_garbage_collector *gc, int i, int j)
{
	t_intersections	intersections;
	t_intersection	intersection;
	t_computation	*computation;
	t_color			*col;

	intersections = intersect_world(world, ray, gc);
	intersection = hit(intersections, 0);
	if (intersection.object == NULL)
		return (get_black(gc));
	computation = prepare_computations(&intersection, ray, world->light, gc);

	// t_vector *p = computation->point;
	// printf("%d %d : %f %f %f : %f\n", i, j, p->dim[0], p->dim[1],p->dim[2], intersection.t);

	col = shade_hit(world, computation, gc);
	return (col);
}
