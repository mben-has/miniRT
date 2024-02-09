/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:57:00 by marschul          #+#    #+#             */
/*   Updated: 2024/02/09 21:48:43 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

t_vector	*vector_cast(t_vector_p *vector_parsing, t_garbage_collector *gc)
{
	t_vector	*v;

	v = vector(vector_parsing->coordinate[0], vector_parsing->coordinate[1], vector_parsing->coordinate[2], gc);
	return (v);
}

t_color	*color_cast(t_vector_p *vector_parsing, t_garbage_collector *gc)
{
	t_color	*col;

	col = color(vector_parsing->coordinate[0], vector_parsing->coordinate[1], vector_parsing->coordinate[2], gc);
	return (col);	
}

void	init_base(t_world *world)
{
	world->nr_objects = 0;
}

void	init_light(t_scene *scene, t_light *light, t_garbage_collector *gc)
{
	light->intensity = scene->light.brightness_ratio;
	light->position = vector_cast(scene->light.point, gc);
}

t_matrix	*get_matrix_sphere(t_sphere_p *sphere_parsing, t_garbage_collector *gc)
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

void	fill_data_sphere(t_sphere *sphere, t_sphere_p *sphere_parsing, t_ambient ambient, t_garbage_collector *gc)
{
	sphere->material.color = color_cast(sphere_parsing->color, gc);
	sphere->material.ambient = ambient.lighting_ratio;
	sphere->material.diffuse = DIFFUSE;
	sphere->material.specular = SPECULAR;
	sphere->material.shininess = SHININESS;
	sphere->transformation_matrix = get_matrix_sphere(sphere_parsing, gc);
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
		obj->sphere = sphere;
		obj->plane = NULL;
		obj->cylinder = NULL;
		world->nr_objects++;
		fill_data_sphere(sphere, scene->spheres[i], scene->ambient, gc);
		i++;
	}
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
		plane = (t_plane *) malloc(sizeof(t_plane));
		if (plane == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, plane);
		obj->plane = plane;
		obj->sphere = NULL;
		obj->cylinder = NULL;
		world->nr_objects++;
		i++;
	}
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
		obj->id = 's';
		cylinder = (t_cylinder *) malloc(sizeof(t_cylinder));
		if (cylinder == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, cylinder);
		obj->cylinder = cylinder;
		obj->plane = NULL;
		obj->sphere = NULL;
		world->nr_objects++;
		i++;
	}
}

void	init_objects(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int	nr_objects;

	nr_objects = scene->nr_spheres + scene->nr_planes + scene->nr_cylinders;
	world->objects = (t_object *) malloc (nr_objects * sizeof(t_object));
	if (world->objects == NULL)
		exit_function(gc, "malloc failed\n", 1, 1);
	else
		add_pointer_node(gc, world->objects);
	add_spheres(scene, world, gc);
	add_planes(scene, world, gc);
	add_cylinders(scene, world, gc);
}

/*
Initializes world and camera with the data in scene.
*/
void	init_world(t_scene *scene, t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	init_base(world);
	init_light(scene, &world->light, gc);
	init_objects(scene, world, gc);
	// init_camera(scene, camera, gc);
}
