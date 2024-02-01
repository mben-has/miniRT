/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:11:23 by marschul          #+#    #+#             */
/*   Updated: 2024/02/01 21:37:28 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	check_ambient(char **split, t_scene *scene)
{
	// check for right element and right amount of words
	if (word_length(split) != 3 || ft_strlen(split[0]) != 1 || split[0][0] != 'A')
		return (0);

	// dummy for reading in double
	if (read_double(split[1], &scene->ambient.lighting_ratio) == 0)
		return (0);

	// reading in int triple
	if (read_color(split[2], &scene->ambient.color) == 0)
		return (0);
	return (1);
}

int check_camera(char **split, t_scene *scene)
{
	return (1);
}

int check_light(char **split, t_scene *scene)
{
	return (1);
}

int check_sphere(char **split, t_scene *scene)
{
	return (1);
}

int check_plane(char **split, t_scene *scene)
{
	return (1);
}

int check_cylinder(char **split, t_scene *scene)
{
	return (1);
}