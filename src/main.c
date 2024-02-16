/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/16 16:52:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	main(int argc, char **argv)
{
	int					error;
	t_scene				scene;
	t_garbage_collector *gc;
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

	error = raytracing(&world, &camera, gc);
	if (error != 0)
		exit(error);
	
	free_all(gc);

	return (0);	
}