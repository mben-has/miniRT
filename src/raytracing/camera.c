/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:41:41 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/03 22:35:37 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_camera	*init_camera(t_vector *point, t_vector *orientation, int fov,t_garbage_collector *gc)
{
	t_camera    *cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
        exit_function(gc, "error while init camera\n", 1, true);
    else
        add_pointer_node(gc, cam);
    cam->point = point;
    cam->orientation = orientation;
    cam->fov = fov;
    cam->distance = ((WIDTH / 2) / tan(fov/((2.0 * 180.0) /M_PI)));
    return (cam);
}