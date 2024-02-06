/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:10:50 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/06 08:08:38 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
void setup_scene(t_scene **scene, t_garbage_collector *gc)
{
    setup_camera(&((*scene)->camera), gc);
}
int		raytracing(t_scene *scene, t_garbage_collector *gc)
{
    
    // t_vector *pixel_center;
    t_vector *ray_direction;
    t_ray *ray;
    t_vector *v1;
    t_vector *v2;
   
  
    
    setup_scene(&scene, gc);

    
    
   
    t_vector *vpu= init_vector(VP_WIDTH, 0, 0, gc);
    t_vector *vpv= init_vector(0, -VP_HEIGHT, 0, gc);
    t_vector *dpu= scalar_division(vpu, WIDTH, gc);
    t_vector *dpv= scalar_division(vpv, HEIGHT, gc);
    t_vector *p_upper_left = vector_difference(scene->camera.point, init_vector(0,0,scene->camera.distance, gc), gc);
    p_upper_left = vector_difference(p_upper_left, scalar_division(vpu,2, gc), gc);
    p_upper_left = vector_difference(p_upper_left, scalar_division(vpv,2, gc), gc);
    t_vector *pixel00_loc = vector_sum(dpu, dpv,gc);
    pixel00_loc = scalar_product(pixel00_loc, 0.5, gc);
    pixel00_loc = vector_sum(p_upper_left, pixel00_loc,gc);
    printf("dis = %f\n", scene->camera.distance);

    int i = 0;
    int j = 0;

    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    mlx_image_to_window(mlx, img, 0, 0);
    while (j <  HEIGHT)
    {
        i = 0;
        while (i < WIDTH)
        {
            // pixel_center = vector_sum(p_upper_left, vector_sum(scalar_product(dpu, i, gc), scalar_product(dpv, j, gc), gc), gc);
            v1 = vector_sum(init_vector(i,0,0,gc), init_vector(0,-j,0,gc), gc);
            v2 = vector_sum(scene->camera.radius, v1, gc);
            ray_direction = vector_sum(scene->camera.o_vp, v2, gc);
            ray = init_ray(scene->camera.point, ray_direction, gc);
            check_hit(&scene, &ray,gc);
            if(ray->clo != NULL)
                mlx_put_pixel(img, i, j, argb_to_hex(ray->clo->color));
            i++;
        }
        j++;
    }
   
    mlx_loop(mlx);
    return (0);

    
}
