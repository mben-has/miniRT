/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:57:00 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 03:04:53 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

void	init_base(t_world *world)
{
	world->nr_objects = 0;
}

void	init_light(t_scene *scene, t_light *light, t_garbage_collector *gc)
{
	light->intensity = scene->light.brightness_ratio;
	light->position = vector_cast(scene->light.point, gc);
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

void	init_world(t_scene *scene, t_world *world, t_camera *camera, \
	t_garbage_collector *gc)
{
	init_base(world);
	init_light(scene, &world->light, gc);
	init_objects(scene, world, gc);
	init_camera(scene, camera, gc);
}
