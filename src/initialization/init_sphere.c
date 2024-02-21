/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:25:51 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/20 22:26:02 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_matrix	*set_matrix_sphere(t_sphere_p *sphere_parsing, \
	t_garbage_collector *gc)
{
	t_matrix	*m1;
	t_matrix	*m2;
	t_matrix	*m3;
	t_vector	*v;
	double		radius;

	v = vector_cast(sphere_parsing->point, gc);
	m1 = translation(v, gc);
	radius = sphere_parsing->diameter / 2;
	v = vector(radius, radius, radius, gc);
	m2 = scaling(v, gc);
	m3 = matrix_mult_m(m1, m2, gc);
	return (m3);
}

void	fill_data_sphere(t_sphere *sphere, t_sphere_p *sphere_parsing, \
	t_ambient ambient, t_garbage_collector *gc)
{
	t_color	*col;

	sphere->material.color = color_cast(sphere_parsing->color, gc);
	col = color_cast(ambient.color, gc);
	sphere->material.ambient = color_mult(col, ambient.lighting_ratio, gc);
	sphere->material.diffuse = DIFFUSE;
	sphere->material.specular = SPECULAR;
	sphere->material.shininess = SHININESS;
	sphere->transformation_matrix = set_matrix_sphere(sphere_parsing, gc);
}

void	add_spheres(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int			i;
	t_object	*obj;
	t_sphere	*sphere;

	i = 0;
	while (i < scene->nr_spheres)
	{
		obj = &world->objects[world->nr_objects];
		obj->id = 's';
		sphere = (t_sphere *) malloc(sizeof(t_sphere));
		if (sphere == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, sphere);
		sphere->transformation_matrix = identity_matrix(gc);
		obj->sphere = sphere;
		obj->plane = NULL;
		obj->cylinder = NULL;
		world->nr_objects++;
		fill_data_sphere(sphere, scene->spheres[i], scene->ambient, gc);
		i++;
	}
}
