/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:40:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/11 22:38:19 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"

// t_ray *get_ray(t_camera *cam, int i, int j, t_garbage_collector *gc)
// {
// 	   t_vector *v1;
// 	   t_vector *vo;
// 	   t_vector *p;
// 		t_ray *r;

// 		vo = vector_subtract((*cam).pixel00, (*cam).point, gc);
// 	   v1 = vector_add( scalar_mult((*cam).v_width, i, gc) , scalar_mult((*cam).v_height,-j, gc), gc); 
// 	printf("v1 coordiantes (%f, %f, %f, %f) \n", v1->dim[0], v1->dim[1],v1->dim[2],v1->dim[3] );
// 	//    v1 = vector_add(v1, (*cam).pixel00, gc);
// 	   vo = vector_add(vo, v1, gc);
// 	printf("*********************************************************************************\n");
// 	printf("v0 coordiantes (%f, %f, %f, %f) \n", vo->dim[0], vo->dim[1],vo->dim[2],vo->dim[3] );
//     r = ray((*cam).point, v1, gc);
// 	   p = point(0, 0 ,0, gc);
// 		// p->dim[0] = (*cam).pixel00[0] ;
//     // t_vector *ray_direction;
//     // t_ray *ray;
//     // t_vector *v1;
//     // t_vector *v2;

// 	// v1 = vector_subtract((*cam).pixel00, (*cam).point, gc);
//     // v1 = vector_sum(init_vector(i + 0.5 ,0,0,gc), init_vector(0,-j -0.5,0,gc), gc);
//     // v2 = vector_sum((*scene)->camera.radius, v1, gc);
//     // ray_direction = vector_sum((*scene)->camera v2, gc);
//     return (r);
// }

void	draw(t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	int			i;
	int			j;
	t_ray		*ray;
	mlx_t		*mlx;
	mlx_image_t	*img;

	i = 0;
	j = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			// ray = get_ray(camera, i, j, gc);
			// if( i == 1 && j ==0)
			return;
			// if (check_hit(&(*scene), &ray, gc))
			// ray = ray();
			// ray = ray((*camera).point, ,gc);
			// mlx_put_pixel(img, i, j, argb_to_hex(ray->clo->color));
			i++;
		}
		j++;
	}
	mlx_loop(mlx);
}

int	raytracing(t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	(void)world;
	(void)camera;

	draw(NULL, camera, gc);
	return (0);
}
