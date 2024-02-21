/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:27:42 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/21 17:40:17 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

void	set_v_width_length(t_vector *aux, t_camera *cam, \
	t_garbage_collector *gc)
{
	(*cam).v_width = normalize(cross(aux, (*cam).orientation, gc), gc);
	(*cam).v_width = scalar_mult((*cam).v_width, ((*cam).width) * 0.5, gc);
	(*cam).v_height = normalize(cross((*cam).orientation, (*cam).v_width, gc),
			gc);
	(*cam).v_height = scalar_mult((*cam).v_height, ((*cam).height) * 0.5, gc);
	(*cam).v_cam_canvas = scalar_mult((*cam).orientation, (*cam).focal_length,
			gc);
	(*cam).v_cam_canvas = vector_add((*cam).v_cam_canvas, (*cam).point, gc);
}

void	set_atributes(double *half_diag, double *fov_radians, t_camera *cam)
{
	*fov_radians = (*cam).fov * (M_PI / 180.0);
	*half_diag = sqrt(((((*cam).height) * 0.5) * (((*cam).height) * 0.5)) \
		+ ((((*cam).width) * 0.5)
				* (((*cam).width) * 0.5)));
	(*cam).focal_length = (*half_diag) / tan((*fov_radians) / 2.0);
}

void	set_normal_vector(t_camera *cam, t_vector **aux,
		t_garbage_collector *gc)
{
	if ((*cam).orientation->dim[0] == 0.0f
		&& ((*cam).orientation->dim[1] == 1.0f || \
		(*cam).orientation->dim[1] == -1.0f) \
		&& (*cam).orientation->dim[2] == 0.0f)
	{
		*aux = vector(0, 0.0, -1.0, gc);
	}
	else
	{
		*aux = vector(0.0, 1.0, 0.0, gc);
	}
}

void	init_camera(t_scene *scene, t_camera *cam, t_garbage_collector *gc)
{
	double		fov_radians;
	t_vector	*aux;
	double		half_diag;

	if (!is_vector_normal(scene->camera.orientation, gc))
		exit_function(gc, "camera vector is not normal\n", 1, true);
	(*cam).width = WIDTH;
	(*cam).height = (int)(((*cam).width) / (16.9 / 9.0));
	(*cam).point = point(scene->camera.point->coordinate[0],
			scene->camera.point->coordinate[1],
			scene->camera.point->coordinate[2], gc);
	(*cam).orientation = vector(scene->camera.orientation->coordinate[0],
			scene->camera.orientation->coordinate[1],
			scene->camera.orientation->coordinate[2], gc);
	(*cam).fov = scene->camera.fov;
	set_atributes(&half_diag, &fov_radians, cam);
	set_normal_vector(cam, &aux, gc);
	set_v_width_length(aux, cam, gc);
	aux = vector_subtract((*cam).v_height, (*cam).v_width, gc);
	(*cam).pixel00 = vector_add((*cam).v_cam_canvas, aux, gc);
	(*cam).v_width = normalize((*cam).v_width, gc);
	(*cam).v_height = normalize((*cam).v_height, gc);
}
	// printf("fov = %d\n", (*cam).fov);
	// printf("focal length = %f\n", (*cam).focal_length);
