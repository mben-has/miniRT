/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:11:23 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 11:34:52 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

/*
Checks and reads in ambient
*/
bool	check_ambient(char **split, t_scene *scene, t_garbage_collector *gc)
{
	if (word_length(split) != 3 || ft_strlen(split[0]) != 1 || split[0][0] != 'A')
		return (exit_function(gc, "Error\nMalformed element id\n", 8, false));
	if (read_double(split[1], &scene->ambient.lighting_ratio, 0.0, 1.0) == false)
		return (exit_function(gc, "Error\nNot a double or not in range", 9, false));
	if (read_color(split[2], &scene->ambient.color, gc) == false)
		return (exit_function(gc, "Error\nNot a color\n", 10, false));
	return (true);
}

/*
Checks and reads in camera
*/
bool	check_camera(char **split, t_scene *scene, t_garbage_collector *gc)
{
	if (word_length(split) != 4 || ft_strlen(split[0]) != 1 || split[0][0] != 'C')
		return (exit_function(gc, "Error\nMalformed element id\n", 8, false));
	if (read_vector(split[1], &scene->camera.point, 0, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	if (read_vector(split[2], &scene->camera.orientation, 1, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	scene->camera.fov = read_byte(split[3], 0, 180);
	if (scene->camera.fov == -1)
		return (exit_function(gc, "Error\nNot a number or not in range", 12, false));
	return (true);
}

/*
Checks and reads in light
*/
bool	check_light(char **split, t_scene *scene, t_garbage_collector *gc)
{
	if (word_length(split) != 4 || ft_strlen(split[0]) != 1 || split[0][0] != 'L')
		return (exit_function(gc, "Error\nMalformed element id\n", 8, false));
	if (read_vector(split[1], &scene->light.point, 0, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	if (read_double(split[2], &scene->light.brightness_ratio, 0.0, 1.0) == false)
		return (exit_function(gc, "Error\nNot a double or not in range", 9, false));
	return (true);
}

/*
Checks and reads in spheres
*/
bool	check_sphere(char **split, t_scene *scene, t_garbage_collector *gc)
{
	t_sphere_p	*sphere;

	if (scene->nr_spheres >= 100)
		return (exit_function(gc, "Error\nToo many objects of this type\n", 13, false));
	sphere = (t_sphere_p *) malloc(sizeof(t_sphere_p));
	if (sphere == NULL)
		return (exit_function(gc, "Error\nMalloc failure", 1, false));
	add_pointer_node(gc, sphere);
	scene->spheres[scene->nr_spheres] = sphere;
	if (word_length(split) != 4 || ft_strlen(split[0]) != 2 || split[0][0] != 's' || split[0][1] != 'p')
		return (exit_function(gc, "Error\nMalformed element id\n", 8, false));
	sphere->id = 's';
	if (read_vector(split[1], &sphere->point, 0, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	if (read_double(split[2], &sphere->diameter, 0, HUGE_VAL) == false)
		return (exit_function(gc, "Error\nNot a double or not in range", 9, false));
	if (read_color(split[3], &sphere->color, gc) == false)
		return (exit_function(gc, "Error\nNot a color\n", 10, false));
	scene->nr_spheres++;
	return (true);
}

/*
Checks and reads in planes
*/
bool	check_plane(char **split, t_scene *scene, t_garbage_collector *gc)
{
	t_plane_p	*plane;

	if (scene->nr_planes >= 100)
		return (exit_function(gc, "Error\nToo many objects of this type\n", 13, false));
	plane = (t_plane_p *) malloc(sizeof(t_plane_p));
	if (plane == NULL)
		return (false);
	add_pointer_node(gc, plane);
	scene->planes[scene->nr_planes] = plane;
	if (word_length(split) != 4 || ft_strlen(split[0]) != 2 || split[0][0] != 'p' || split[0][1] != 'l')
		return (exit_function(gc, "Error\nMalformed element id\n", 8, false));
	plane->id = 'p';
	if (read_vector(split[1], &plane->point, 0, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	if (read_vector(split[2], &plane->normal_vector, 1, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	if (read_color(split[3], &plane->color, gc) == false)
		return (exit_function(gc, "Error\nNot a color\n", 10, false));
	scene->nr_planes++;
	return (true);
}

/*
Checks and reads in cylinders
*/
bool	check_cylinder(char **split, t_scene *scene, t_garbage_collector *gc)
{
	t_cylinder_p	*cylinder;

	if (scene->nr_cylinders >= 100)
		return (exit_function(gc, "Error\nToo many objects of this type\n", 13, false));
	cylinder = (t_cylinder_p *) malloc(sizeof(t_cylinder_p));
	if (cylinder == NULL)
		return (false);
	add_pointer_node(gc, cylinder);
	scene->cylinders[scene->nr_cylinders] = cylinder;
	if (word_length(split) != 6 || ft_strlen(split[0]) != 2 || split[0][0] != 'c' || split[0][1] != 'y')
		return (exit_function(gc, "Error\nMalformed element id\n", 8, false));
	cylinder->id = 'c';
	if (read_vector(split[1], &cylinder->point, 0, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	if (read_vector(split[2], &cylinder->axis_vector, 1, gc) == false)
		return (exit_function(gc, "Error\nNot a vector or not in range", 11, false));
	if (read_double(split[3], &cylinder->diameter, 0, HUGE_VAL) == false)
		return (exit_function(gc, "Error\nNot a double or not in range", 9, false));
	if (read_double(split[4], &cylinder->height, 0, HUGE_VAL) == false)
		return (exit_function(gc, "Error\nNot a double or not in range", 9, false));
	if (read_color(split[5], &cylinder->color, gc) == false)
		return (exit_function(gc, "Error\nNot a color\n", 10, false));
	scene->nr_cylinders++;
	return (true);
}
