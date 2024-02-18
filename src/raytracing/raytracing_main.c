/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:40:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/18 04:19:37 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"

t_ray *get_ray(t_camera *cam, int i, int j, t_garbage_collector *gc)
{
	   t_vector *v1;
	   t_vector *vo;
	   t_vector *p;
		t_ray *r;

		vo = vector_subtract((*cam).pixel00, (*cam).point, gc);
	   v1 = vector_add( scalar_mult((*cam).v_width, i, gc) , scalar_mult((*cam).v_height,-j, gc), gc); 
	// printf("v1 coordinates (%f, %f, %f, %f) \n", v1->dim[0], v1->dim[1],v1->dim[2],v1->dim[3] );
	//    v1 = vector_add(v1, (*cam).pixel00, gc);
	   vo = vector_add(vo, v1, gc);
	// printf("*********************************************************************************\n");
	// printf("RAY coordinates (%f, %f, %f, %f) \n", vo->dim[0], vo->dim[1],vo->dim[2],vo->dim[3] );
    r = ray((*cam).point, vo, gc);
	//    p = point(0, 0 ,0, gc);
		// p->dim[0] = (*cam).pixel00[0] ;
    // t_vector *ray_direction;
    // t_ray *ray;
    // t_vector *v1;
    // t_vector *v2;

	// v1 = vector_subtract((*cam).pixel00, (*cam).point, gc);
    // v1 = vector_sum(init_vector(i + 0.5 ,0,0,gc), init_vector(0,-j -0.5,0,gc), gc);
    // v2 = vector_sum((*scene)->camera.radius, v1, gc);
    // ray_direction = vector_sum((*scene)->camera v2, gc);
	p = r->direction;
	// printf("%d %d : %f %f %f\n", i, j, p->dim[0], p->dim[1],p->dim[2]);
    return (r);
}

void	draw(t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	int			i;
	int			j;
	t_ray		*ray;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_color 	*color_vector;
	unsigned int	color_hex;
	t_intersections xs;
	t_intersection ht;

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
			ray = get_ray(camera, i, j, gc);
			color_vector = color_at(world, ray, gc);
			color_hex = rgb_to_hex(color_vector);
			mlx_put_pixel(img, i, j, color_hex);
		
			i++;
		}
		j++;
	}
	mlx_loop(mlx);
}

int	raytracing(t_world *world, t_camera *camera, t_garbage_collector *gc)
{

	
	draw(world, camera, gc);
	


	return (0);
}
