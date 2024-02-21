/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:40:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 02:40:25 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{	
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}


t_ray	*get_ray(t_camera *cam, int i, int j, t_garbage_collector *gc)
{
	t_vector	*v1;
	t_vector	*vo;
	t_vector	*p;
	t_ray		*r;

	vo = vector_subtract((*cam).pixel00, (*cam).point, gc);
	v1 = vector_add(scalar_mult((*cam).v_width, i, gc), \
		scalar_mult((*cam).v_height, -j, gc), gc);
	vo = vector_add(vo, v1, gc);
	r = ray((*cam).point, vo, gc);
	return (r);
}

void	draw(t_world *world, mlx_image_t **img, t_camera *camera,
		t_garbage_collector *gc)
{
	int				i;
	int				j;
	t_ray			*ray;
	t_color			*color_vector;
	unsigned int	color_hex;


			

            t_intersections	xs;
	t_intersection	ht;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray = get_ray(camera, i, j, gc);
			xs= intersect_world(world, ray, gc);
				ht = hit(xs, ray->original_length);
				// if(ray->direction->dim[0] == 0 && ray->direction->dim[2] == 0)
				// {
				// 	printf("xs[0] = %f\n", xs.xs[0]);
				// 	printf("xs[1] = %f\n", xs.xs[1]);
				// 	printf("ray length = %f\n", ray->original_length);
					
				// 	if (ht.object != NULL)
				// 	{
				// 		printf("ray.direction = (%f, %f, %f) \n",
				// 				ray->direction->dim[0], ray->direction->dim[1],
				// 				ray->direction->dim[2]);
				// 		printf("ray.origin = (%f, %f, %f) \n", ray->origin->dim[0],
				// 				ray->origin->dim[1], ray->origin->dim[2]);
				// 		// printf("ray.lenght = %f \n", ray->original_length);
				// 		printf("hit = %f\n", ht.t);
				// 		mlx_put_pixel(*img, i, j, 0xFF0000FF);
				// 	}
				// 	// exit(1);
				// }

			color_vector = color_at(world, ray, gc);
			color_hex = rgb_to_hex(color_vector);
			mlx_put_pixel(*img, i, j, color_hex);
			i++;
		}
		j++;
	}
}

int	raytracing(t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	// int i = 0;
	// while(i < world->nr_objects)
	// {
	// 	i++;
	// }
	// printf("number of objects = %d\n", i);
	// exit(1);

	mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	draw(world, &img, camera, gc);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	return (0);
}
