/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:24:16 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/21 17:33:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_matrix	*set_matrix_plane(t_plane_p *plane_parsing,
	t_garbage_collector *gc)
{
	t_matrix	*m1;
	t_matrix	*m2;
	t_matrix	*result;
	t_vector	*v;

	v = vector_cast(plane_parsing->point, gc);
	m1 = translation(v, gc);
	m2 = get_rotation_matrix(vector(plane_parsing->normal_vector->coordinate[0],
				plane_parsing->normal_vector->coordinate[1],
				plane_parsing->normal_vector->coordinate[2], gc), gc);
	result = matrix_mult_m(m1, m2, gc);
	return (result);
}

void	fill_data_plane(t_scene *scene, t_plane *plane,
		t_plane_p *plane_parsing, t_garbage_collector *gc)
{
	t_color		*col;
	t_ambient	ambient;

	ambient = scene->ambient;
	if (!is_vector_normal(plane_parsing->normal_vector, gc))
	{
		exit_function(gc, "plane vector is not normal\n", 1, true);
	}
	plane->material.color = color_cast(plane_parsing->color, gc);
	col = color_cast(ambient.color, gc);
	plane->material.ambient = color_mult(col, ambient.lighting_ratio, gc);
	plane->material.diffuse = DIFFUSE;
	plane->material.specular = SPECULAR;
	plane->material.shininess = SHININESS;
	plane->transformation_matrix = set_matrix_plane(plane_parsing, gc);
}

void	add_planes(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int			i;
	t_object	*obj;
	t_plane		*plane;

	i = 0;
	while (i < scene->nr_planes)
	{
		obj = &world->objects[world->nr_objects];
		obj->id = 'p';
		plane = (t_plane *)malloc(sizeof(t_plane));
		if (plane == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, plane);
		obj->plane = plane;
		obj->sphere = NULL;
		obj->cylinder = NULL;
		world->nr_objects++;
		fill_data_plane(scene, plane, scene->planes[i], gc);
		i++;
	}
}
