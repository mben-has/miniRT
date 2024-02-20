/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:40:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/20 21:45:14 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"

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

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray = get_ray(camera, i, j, gc);
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

	mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	draw(world, &img, camera, gc);
	mlx_loop(mlx);
	return (0);
}
