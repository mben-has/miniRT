/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:40:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 23:14:33 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"
#include "structure_rtc.h"

int	raytracing(t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	(void)world;
	(void)camera;

	t_matrix *matrix;
	matrix = identity_matrix(gc);
	char *hello = malloc(sizeof(char) * 5);
	add_pointer_node(gc, hello);
	hello = "helo\0";
	return (0);
}
