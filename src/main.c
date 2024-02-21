/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 20:20:34 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_scene				scene;
	t_garbage_collector	*gc;
	t_world				world;
	t_camera			camera;

	if (argc != 2)
	{
		print_usage();
		exit(1);
	}
	gc = init_garbage_collector();
	parsing(argv[1], &scene, gc);
	init_world(&scene, &world, &camera, gc);
	raytracing(&world, &camera, gc);
	free_all(gc);
	return (0);
}
