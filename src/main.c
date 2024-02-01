/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/01 13:08:42 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	main(int argc, char **argv)
{
	int		error;
	t_scene	scene;

	if (argc != 2)
	{
		print_usage();
		exit(1);
	}
	error = parsing(argv[1], &scene);
	if (error != 0)
		exit(error);
	error = raytracing(&scene);
	if (error != 0)
		exit(error);
	return (0);	
}