/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:45 by marschul          #+#    #+#             */
/*   Updated: 2024/02/20 16:44:10 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

/*
Checks and reads in cylinders
*/
bool	check_cylinder(char **split, t_scene *scene, t_garbage_collector *gc)
{
	t_cylinder_p	*cylinder;

	if (scene->nr_cylinders >= 100)
		return (printf("Error\nToo many objects of this type\n"), false);
	cylinder = (t_cylinder_p *) malloc(sizeof(t_cylinder_p));
	if (cylinder == NULL)
		return (false);
	add_pointer_node(gc, cylinder);
	scene->cylinders[scene->nr_cylinders] = cylinder;
	if (word_length(split) != 6 || ft_strlen(split[0]) != 2 || \
		split[0][0] != 'c' || split[0][1] != 'y')
		return (printf("Error\nMalformed element id\n"), false);
	cylinder->id = 'c';
	if (read_vector(split[1], &cylinder->point, 0, gc) == false)
		return (printf("Error\nNot a vector or not in range"), false);
	if (read_vector(split[2], &cylinder->axis_vector, 1, gc) == false)
		return (printf("Error\nNot a vector or not in range"), false);
	if (read_double(split[3], &cylinder->diameter, 0, HUGE_VAL) == false)
		return (printf("Error\nNot a double or not in range"), false);
	if (read_double(split[4], &cylinder->height, 0, HUGE_VAL) == false)
		return (printf("Error\nNot a double or not in range"), false);
	if (read_color(split[5], &cylinder->color, gc) == false)
		return (printf("Error\nNot a color\n"), false);
	scene->nr_cylinders++;
	return (true);
}
