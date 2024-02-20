/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:26:41 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/20 23:32:52 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_matrix	*set_matrix_cylinder(t_cylinder_p *cp, t_garbage_collector *gc)
{
	t_matrix	*m1;
	t_matrix	*m2;
	t_matrix	*m4;
	t_matrix	*r;
	t_vector	*v;

	v = vector_cast(cp->point, gc);
	m1 = translation(v, gc);
	v = vector(cp->diameter * 0.5, cp->diameter * 0.5, cp->diameter * 0.5, gc);
	m2 = scaling(v, gc);
	r = get_rotation_matrix(vector(cp->axis_vector->coordinate[0], \
		cp->axis_vector->coordinate[1], cp->axis_vector->coordinate[2], gc), \
		gc);
	m4 = matrix_mult_m(m1, matrix_mult_m(r, m2, gc), gc);
	return (m4);
}

void	fill_data_cylinder(t_cylinder *cylinder, t_cylinder_p *cylinder_parsing,
		t_ambient ambient, t_garbage_collector *gc)
{
	t_color	*col;

	if (!is_vector_normal(cylinder_parsing->axis_vector, gc))
	{
		exit_function(gc, "cylinder vector is not normal\n", 1, true);
	}
	cylinder->material.color = color_cast(cylinder_parsing->color, gc);
	col = color_cast(ambient.color, gc);
	cylinder->material.ambient = color_mult(col, ambient.lighting_ratio, gc);
	cylinder->material.diffuse = DIFFUSE;
	cylinder->material.specular = SPECULAR;
	cylinder->material.shininess = SHININESS;
	cylinder->minimum = -(cylinder_parsing->height / 2) \
		/ (cylinder_parsing->diameter * 2);
	cylinder->maximum = (cylinder_parsing->height / 2) \
		/ (cylinder_parsing->diameter * 2);
	cylinder->transformation_matrix = set_matrix_cylinder(cylinder_parsing, gc);
}

void	add_cylinders(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int			i;
	t_object	*obj;
	t_cylinder	*cylinder;

	i = 0;
	while (i < scene->nr_cylinders)
	{
		obj = &world->objects[world->nr_objects];
		obj->id = 'c';
		cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
		if (cylinder == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, cylinder);
		obj->cylinder = cylinder;
		obj->plane = NULL;
		obj->sphere = NULL;
		world->nr_objects++;
		fill_data_cylinder(cylinder, scene->cylinders[i], scene->ambient, gc);
		i++;
	}
}
