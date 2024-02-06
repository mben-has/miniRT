/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:10:50 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/06 09:49:22 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

void	setup_scene(t_scene **scene, t_garbage_collector *gc)
{
	setup_camera(&((*scene)->camera), gc);
}

void	draw(t_scene **scene, t_garbage_collector *gc)
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
			ray = get_ray(&(*scene), i, j, gc);
			if (check_hit(&(*scene), &ray, gc))
				mlx_put_pixel(img, i, j, argb_to_hex(ray->clo->color));
			i++;
		}
		j++;
	}
	mlx_loop(mlx);
}

int	raytracing(t_scene *scene, t_garbage_collector *gc)
{
	setup_scene(&scene, gc);
	draw(&scene, gc);
	return (0);
}
