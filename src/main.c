/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/06 03:26:05 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	main(int argc, char **argv)
{
	int		error;
	t_scene	scene;
	t_garbage_collector *gc;
	
	gc = init_garbage_collector();
	if (argc != 2)
	{
		print_usage();
		exit(1);
	}
	error = parsing(argv[1], &scene, gc);
	if (error != 0)
		exit(error);
	// system("leaks minirt"); //<====== uncomment this line to see the weird leaks
	
	error = raytracing(&scene, gc);
	if (error != 0)
		exit(error);
	

	free_all(gc);
	// system("leaks minirt");
	return (0);	
}