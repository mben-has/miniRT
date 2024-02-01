/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:29 by marschul          #+#    #+#             */
/*   Updated: 2024/02/01 11:38:07 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	main(int argc, char **argv)
{
	int		parsing_error;
	t_scene	scene;

	if (argc != 2)
	{
		print_usage();
		exit(1);
	}
	parsing_error = parsing(argv[1], &scene);
	if (parsing_error != 0)
		exit(parsing_error);
	//raytracing(&scene);
}