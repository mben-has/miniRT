/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:55:32 by marschul          #+#    #+#             */
/*   Updated: 2024/02/06 19:55:13 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

void	print_usage(void)
{
	printf("Usage: ./minirt *.rt\n");
}

/*
Initializes world and camera with the data in scene.
*/
int	init_world(t_scene *scene, t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	t_vector	test_vector1 = {1.0, 2.0, 3.0, 0.0};
	t_vector	test_vector2 = {1.0, 2.0, 3.0, 0.0};
	t_vector	*test_vector3;

	test_vector3 = vector_add(test_vector1, test_vector2);
	printf("%f %f %f %f\n", *test_vector3[0], *test_vector3[1], *test_vector3[2], *test_vector3[4]);
	return (0);
}