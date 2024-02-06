/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:41:41 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/06 09:10:03 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

void	setup_camera(t_camera *cam, t_garbage_collector *gc)
{
	int		fov;
	double	x;
	double	fov_radians;

	fov = cam->fov;
	fov_radians = fov * (M_PI / 180.0);
	x = sqrt(((HEIGHT * 0.5) * (HEIGHT * 0.5)) + ((WIDTH * 0.5) * (WIDTH
					* 0.5)));
	cam->distance = x / tan(fov_radians / 2.0);
	cam->o_vp = init_vector(cam->distance * cam->orientation->coordinate[0],
			cam->distance * cam->orientation->coordinate[1],
			cam->distance * cam->orientation->coordinate[2], gc);
	cam->radius = vector_difference(init_vector(0, HEIGHT * 0.5,
				cam->distance, gc), init_vector(WIDTH * 0.5, 0,
				cam->distance, gc), gc);
}
