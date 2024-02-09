/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 23:15:47 by mben-has         ###   ########.fr       */
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
	error = parsing(argv[1], &scene, gc);
	if (error != 0)
		exit(error);
	
	error = init_world(&scene, &world, &camera, gc);
	if (error != 0)
		exit(error);

	error = raytracing(&world, &camera, gc);
	if (error != 0)
		exit(error);
	
	free_all(gc);
	system("leaks minirt");
	return (0);	
}