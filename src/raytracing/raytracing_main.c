/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:40:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 17:43:53 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	(void)keydata;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

t_ray	*get_ray(t_camera *cam, int i, int j, t_garbage_collector *gc)
{
	t_vector	*v1;
	t_vector	*vo;
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
	while (j < camera->height)
	{
		i = 0;
		while (i < camera->width)
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

	mlx = mlx_init(camera->width, camera->height, "minirt", true);
	img = mlx_new_image(mlx, camera->width, camera->height);
	mlx_image_to_window(mlx, img, 0, 0);
	draw(world, &img, camera, gc);
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
