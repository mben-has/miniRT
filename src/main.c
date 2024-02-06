/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/06 02:48:22 by mben-has         ###   ########.fr       */
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
	
	error = raytracing(&scene, gc);
	if (error != 0)
		exit(error);
	

	free_all(gc);
	return (0);	
}