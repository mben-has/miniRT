/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:11:23 by marschul          #+#    #+#             */
/*   Updated: 2024/02/02 17:31:24 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	check_ambient(char **split, t_scene *scene)
{
	// check for right element and right amount of words
	if (word_length(split) != 3 || ft_strlen(split[0]) != 1 || split[0][0] != 'A')
		return (0);

	// reading in double
	if (read_double(split[1], &scene->ambient.lighting_ratio) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[2], &scene->ambient.color) == 0)
		return (0);
	return (1);
}

int check_camera(char **split, t_scene *scene)
{
	// check for right element and right amount of words
	if (word_length(split) != 4 || ft_strlen(split[0]) != 1 || split[0][0] != 'C')
		return (0);

	// reading in vector
	if (read_vector(split[1], &scene->camera.point) == 0)
		return (0);

	// reading in vector
	if (read_vector(split[2], &scene->camera.orientation) == 0)
		return (0);

	// reading in int triple
	scene->camera.fov = read_byte(split[3]);
	if (scene->camera.fov == -1)
		return (0);
	return (1);
}

int check_light(char **split, t_scene *scene)
{
	// check for right element and right amount of words
	if (word_length(split) != 4 || ft_strlen(split[0]) != 1 || split[0][0] != 'L')
		return (0);

	// reading in vector
	if (read_vector(split[1], &scene->light.point) == 0)
		return (0);

	// reading in double
	if (read_double(split[2], &scene->light.brightness_ratio) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[3], &scene->ambient.color) == 0)
		return (0);
	return (1);
}

int check_sphere(char **split, t_scene *scene)
{
	// check for right element and right amount of words
	if (word_length(split) != 4 || ft_strlen(split[0]) != 2 || split[0][0] != 's' || split[0][1] != 'p')
		return (0);

	// reading in vector
	if (read_vector(split[1], &scene->spheres[scene->nr_spheres].point) == 0)
		return (0);

	// reading in double
	if (read_double(split[2], &scene->spheres[scene->nr_spheres].diameter) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[3], &scene->spheres[scene->nr_spheres].color) == 0)
		return (0);

	// increase nr
	scene->nr_spheres++;

	return (1);
}

int check_plane(char **split, t_scene *scene)
{
	// check for right element and right amount of words
	if (word_length(split) != 4 || ft_strlen(split[0]) != 2 || split[0][0] != 'p' || split[0][1] != 'l')
		return (0);

	// reading in vector
	if (read_vector(split[1], &scene->planes[scene->nr_planes].point) == 0)
		return (0);

	// reading in vector
	if (read_vector(split[2], &scene->planes[scene->nr_planes].normal_vector) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[3], &scene->planes[scene->nr_planes].color) == 0)
		return (0);

	// increase nr
	scene->nr_planes++;

	return (1);
}

int check_cylinder(char **split, t_scene *scene)
{
	// check for right element and right amount of words
	if (word_length(split) != 6 || ft_strlen(split[0]) != 2 || split[0][0] != 'c' || split[0][1] != 'y')
		return (0);

	// reading in vector
	if (read_vector(split[1], &(scene->cylinders[scene->nr_cylinders].point)) == 0)
		return (0);

	// reading in vector
	if (read_vector(split[2], &scene->cylinders[scene->nr_cylinders].axis_vector) == 0)
		return (0);

	// reading in double
	if (read_double(split[3], &scene->cylinders[scene->nr_cylinders].diameter) == 0)
		return (0);

	// reading in double
	if (read_double(split[4], &scene->cylinders[scene->nr_cylinders].height) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[5], &scene->cylinders[scene->nr_cylinders].color) == 0)
		return (0);
	return (1);
}