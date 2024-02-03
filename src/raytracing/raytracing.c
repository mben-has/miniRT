/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:10:50 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/03 22:29:19 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"





int		raytracing(t_scene *scene, t_garbage_collector *gc)
{
    t_camera *cam;

    cam = init_camera(init_vector(0,0,0,gc), NULL, 60, gc);
    printf("dis = %f\n", cam->distance);
    (void)scene;
    
    // t_vector *color;
    
    // color = init_vector(255, 255 , 255, gc);
    // int i = 0;
    // int j = 0;
    // // mlx_set_setting(MLX_MAXIMIZED, true);
    // mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
    // mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    // // memset(img->pixels, 255, img->width * img->height * BPP);
    // mlx_image_to_window(mlx, img, 0, 0);
    // while (i <  WIDTH)
    // {
    //     j = 0;
    //     while (j < HEIGHT)
    //     {
    //         mlx_put_pixel(img, i, j, argb_to_hex(color));
    //         j++;
    //     }
    //     i++;
    // }
    // mlx_loop(mlx);
    return (0);

    
}