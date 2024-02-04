/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:10:50 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/04 18:52:18 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"





int		raytracing(t_scene *scene, t_garbage_collector *gc)
{
    t_camera *cam;
    t_vector *pixel_center;
    t_vector *ray_direction;
    t_ray *ray;
    t_sphere *sphere;

    
    sphere = init_sphere(init_vector(0,0,-1,gc), 1, gc);
    cam = init_camera(init_vector(0,0,0,gc), NULL, 60, gc);
    cam->distance = 1.0;
    t_vector *vpu= init_vector(VP_WIDTH, 0, 0, gc);
    t_vector *vpv= init_vector(0, -VP_HEIGHT, 0, gc);
    t_vector *dpu= scalar_division(vpu, WIDTH, gc);
    t_vector *dpv= scalar_division(vpv, HEIGHT, gc);
    t_vector *p_upper_left = vector_difference(cam->point, init_vector(0,0,cam->distance, gc), gc);
    p_upper_left = vector_difference(p_upper_left, scalar_division(vpu,2, gc), gc);
    p_upper_left = vector_difference(p_upper_left, scalar_division(vpv,2, gc), gc);
    t_vector *pixel00_loc = vector_sum(dpu, dpv,gc);
    pixel00_loc = scalar_product(pixel00_loc, 0.5, gc);
    pixel00_loc = vector_sum(p_upper_left, pixel00_loc,gc);
    printf("dis = %f\n", cam->distance);
    (void)scene;
    
    t_color *color;
    
    int i = 0;
    int j = 0;
    // mlx_set_setting(MLX_MAXIMIZED, true);
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    // memset(img->pixels, 255, img->width * img->height * BPP);
    mlx_image_to_window(mlx, img, 0, 0);
    while (j <  HEIGHT)
    {
        i = 0;
        while (i < WIDTH)
        {
            pixel_center = vector_sum(p_upper_left, vector_sum(scalar_product(dpu, i, gc), scalar_product(dpv, j, gc), gc), gc);
            ray_direction = vector_difference(pixel_center, cam->point, gc);
            // printf("r[0] = %f ; r[1] = %f ; r[2] = %f\n", ray_direction->coordinate[0],ray_direction->coordinate[1],ray_direction->coordinate[2] );
            ray = init_ray(cam->point, ray_direction, gc);
            color = init_color(init_vector(0, 0 , 255, gc), ray_direction, gc);
            if(hit_sphere(sphere, ray, gc))
                mlx_put_pixel(img, i, j, 0xFF0000FF);
            else
                mlx_put_pixel(img, i, j, argb_to_hex(color->v_color));
            i++;
        }
        j++;
    }
    mlx_loop(mlx);
    return (0);

    
}