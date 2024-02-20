/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:27:42 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/20 22:27:54 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

void	init_camera(t_scene *scene ,t_camera *cam, t_garbage_collector *gc)
{
	double		half_diag; //lenght diagonal across virtual screen * 0.5
	double		fov_radians;
	t_vector	*aux;
	
	(*cam).point = point(scene->camera.point->coordinate[0], scene->camera.point->coordinate[1], scene->camera.point->coordinate[2], gc);
	(*cam).orientation = vector(scene->camera.orientation->coordinate[0], scene->camera.orientation->coordinate[1], scene->camera.orientation->coordinate[2], gc);
	(*cam).fov = scene->camera.fov;
	fov_radians = (*cam).fov * (M_PI / 180.0);
	half_diag = sqrt(((HEIGHT * 0.5) * (HEIGHT * 0.5)) + ((WIDTH * 0.5) * (WIDTH
					* 0.5)));
	(*cam).focal_length = half_diag / tan(fov_radians / 2.0);

 if ((*cam).orientation->dim[0] == 0.0f
        && ((*cam).orientation->dim[1] == 1.0f || (*cam).orientation->dim[1] == -1.0f)
        && (*cam).orientation->dim[2] == 0.0f)
        {
			aux = vector(0 , 0.0, -1.0,gc);
		}
		else
		{
			aux = vector(0.0, 1.0, 0.0,gc);
		}
	
	(*cam).v_width= normalize(cross(aux, (*cam).orientation,  gc), gc); 
	(*cam).v_width = scalar_mult((*cam).v_width  , WIDTH * 0.5, gc);
	(*cam).v_height = normalize(cross((*cam).orientation, (*cam).v_width, gc), gc);
	(*cam).v_height  = scalar_mult((*cam).v_height   , HEIGHT * 0.5, gc);
	(*cam).v_cam_canvas = scalar_mult((*cam).orientation, (*cam).focal_length, gc);
	(*cam).v_cam_canvas = vector_add((*cam).v_cam_canvas, (*cam).point, gc);
	aux = vector_subtract((*cam).v_height, (*cam).v_width, gc);
	(*cam).pixel00 = vector_add((*cam).v_cam_canvas,aux, gc);
	(*cam).v_width= normalize((*cam).v_width, gc);
	(*cam).v_height= normalize((*cam).v_height, gc);
	printf("fov = %d\n", (*cam).fov);
	printf("focal length = %f\n", (*cam).focal_length);
	printf("lenght half_diag = %f\n", half_diag);
	printf("pixel00 (%f, %f, %f, %f)\n", (*cam).pixel00->dim[0], (*cam).pixel00->dim[1], (*cam).pixel00->dim[2], (*cam).pixel00->dim[3]);
	printf("cam_coordinations = (%f, %f, %f, %f)\n", (*cam).point->dim[0], (*cam).point->dim[1],(*cam).point->dim[2], (*cam).point->dim[3]);
	printf("cam_orientation = (%f, %f, %f, %f)\n", (*cam).orientation->dim[0], (*cam).orientation->dim[1],(*cam).orientation->dim[2], (*cam).orientation->dim[3]);
	// printf("v-height_coordinations = (%f, %f, %f, %f)\n", (*cam).v_height->dim[0], (*cam).v_height->dim[1],(*cam).v_height->dim[2], (*cam).v_height->dim[3]);
	// printf("v-width_coordinations = (%f, %f, %f, %f)\n", (*cam).v_width->dim[0], (*cam).v_width->dim[1],(*cam).v_width->dim[2], (*cam).v_width->dim[3]);
}
