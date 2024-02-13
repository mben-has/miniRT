/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:11:23 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 12:06:04 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	check_ambient(char **split, t_scene *scene, t_garbage_collector *gc)
{
	// check for right element and right amount of words
	if (word_length(split) != 3 || ft_strlen(split[0]) != 1 || split[0][0] != 'A')
		return (0);

	// reading in double
	if (read_double(split[1], &scene->ambient.lighting_ratio, 0.0, 1.0) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[2], &scene->ambient.color, gc) == 0)
		return (0);
	return (1);
}

int check_camera(char **split, t_scene *scene, t_garbage_collector *gc)
{
	// check for right element and right amount of words
	if (word_length(split) != 4 || ft_strlen(split[0]) != 1 || split[0][0] != 'C')
		return (0);

	// reading in vector
	if (read_vector(split[1], &scene->camera.point, 0, gc) == 0)
		return (0);

	// reading in vector
	if (read_vector(split[2], &scene->camera.orientation, 1, gc) == 0)
		return (0);

	// reading in int triple
	scene->camera.fov = read_byte(split[3], 0, 180);
	if (scene->camera.fov == -1)
		return (0);
	return (1);
}

int check_light(char **split, t_scene *scene, t_garbage_collector *gc)
{
	// check for right element and right amount of words
	if (word_length(split) != 3 || ft_strlen(split[0]) != 1 || split[0][0] != 'L')
		return (0);

	// reading in vector
	if (read_vector(split[1], &scene->light.point, 0, gc) == 0)
		return (0);

	// reading in double
	if (read_double(split[2], &scene->light.brightness_ratio, 0.0, 1.0) == 0)
		return (0);
	return (1);
}

int check_sphere(char **split, t_scene *scene, t_garbage_collector *gc)
{
    t_sphere_p *sphere;

	// malloc struct
    sphere = (t_sphere_p *) malloc(sizeof(t_sphere_p));
    if(sphere == NULL)
        return (0);
    // add_pointer_node(gc, sphere);
	scene->spheres[scene->nr_spheres] = sphere;

	// check for right element and right amount of words
	if (word_length(split) != 4 || ft_strlen(split[0]) != 2 || split[0][0] != 's' || split[0][1] != 'p')
		return (0);

	// read in id
	sphere->id = 's';

	// reading in vector
	if (read_vector(split[1], &sphere->point, 0, gc) == 0)
		return (0);

	// reading in double
	if (read_double(split[2], &sphere->diameter, 0, 0) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[3], &sphere->color, gc) == 0)
		return (0);

	// increase nr
	scene->nr_spheres++;

	return (1);
}

int check_plane(char **split, t_scene *scene, t_garbage_collector *gc)
{
    t_plane_p *plane;

	// malloc struct
    plane = (t_plane_p *) malloc(sizeof(t_plane_p));
    if(plane == NULL)
        return (0);
    // add_pointer_node(gc, plane);
	scene->planes[scene->nr_planes] = plane;

	// check for right element and right amount of words
	if (word_length(split) != 4 || ft_strlen(split[0]) != 2 || split[0][0] != 'p' || split[0][1] != 'l')
		return (0);

	// read in id
	plane->id = 'p';

	// reading in vector
	if (read_vector(split[1], &plane->point, 0, gc) == 0)
		return (0);

	// reading in vector
	if (read_vector(split[2], &plane->normal_vector, 1, gc) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[3], &plane->color, gc) == 0)
		return (0);

	// increase nr
	scene->nr_planes++;

	return (1);
}

int check_cylinder(char **split, t_scene *scene, t_garbage_collector *gc)
{
   t_cylinder_p	*cylinder;

	// malloc struct
    cylinder = (t_cylinder_p *) malloc(sizeof(t_cylinder_p));
    if(cylinder == NULL)
        return (0);
    // add_pointer_node(gc, cylinder);
	scene->cylinders[scene->nr_cylinders] = cylinder;

	// check for right element and right amount of words
	if (word_length(split) != 6 || ft_strlen(split[0]) != 2 || split[0][0] != 'c' || split[0][1] != 'y')
		return (0);


	// read in id
	cylinder->id = 'c';

	// reading in vector
	if (read_vector(split[1], &cylinder->point, 0, gc) == 0)
		return (0);

	// reading in vector
	if (read_vector(split[2], &cylinder->axis_vector, 1, gc) == 0)
		return (0);

	// reading in double
	if (read_double(split[3], &cylinder->diameter, 0, 0) == 0)
		return (0);

	// reading in double
	if (read_double(split[4], &cylinder->height, 0, 0) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[5], &cylinder->color, gc) == 0)
		return (0);

	// increase nr
	scene->nr_cylinders++;

	return (1);
}