/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:10:50 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/05 13:43:50 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"





// int		raytracing(t_scene *scene, t_garbage_collector *gc)
// {
//     t_camera *cam;
//     t_vector *pixel_center;
//     t_vector *ray_direction;
//     t_ray *ray;
//     t_sphere *sphere;

    
//     sphere = init_sphere(init_vector(0,0,-1,gc), 1, gc);
//     cam = init_camera(init_vector(0,0,0,gc), NULL, 60, gc);
//     // cam->distance = 1.0;
//     t_vector *vpu= init_vector(VP_WIDTH, 0, 0, gc);
//     t_vector *vpv= init_vector(0, -VP_HEIGHT, 0, gc);
//     t_vector *dpu= scalar_division(vpu, WIDTH, gc);
//     t_vector *dpv= scalar_division(vpv, HEIGHT, gc);
//     t_vector *p_upper_left = vector_difference(cam->point, init_vector(0,0,cam->distance, gc), gc);
//     p_upper_left = vector_difference(p_upper_left, scalar_division(vpu,2, gc), gc);
//     p_upper_left = vector_difference(p_upper_left, scalar_division(vpv,2, gc), gc);
//     t_vector *pixel00_loc = vector_sum(dpu, dpv,gc);
//     pixel00_loc = scalar_product(pixel00_loc, 0.5, gc);
//     pixel00_loc = vector_sum(p_upper_left, pixel00_loc,gc);
//     printf("dis = %f\n", cam->distance);
//     (void)scene;
    
//     t_color *color;
    
//     int i = 0;
//     int j = 0;
//     // mlx_set_setting(MLX_MAXIMIZED, true);
//     mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
//     mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
//     // memset(img->pixels, 255, img->width * img->height * BPP);
//     mlx_image_to_window(mlx, img, 0, 0);
//     while (j <  HEIGHT)
//     {
//         i = 0;
//         while (i < WIDTH)
//         {
//             pixel_center = vector_sum(p_upper_left, vector_sum(scalar_product(dpu, i, gc), scalar_product(dpv, j, gc), gc), gc);
//             ray_direction = vector_difference(pixel_center, cam->point, gc);
//             // printf("r[0] = %f ; r[1] = %f ; r[2] = %f\n", ray_direction->coordinate[0],ray_direction->coordinate[1],ray_direction->coordinate[2] );
//             ray = init_ray(cam->point, ray_direction, gc);
//             color = init_color(init_vector(0, 0 , 255, gc), ray_direction, gc);
//             if(hit_sphere(sphere, ray, gc))
//                 mlx_put_pixel(img, i, j, 0xFF0000FF);
//             else
//                 mlx_put_pixel(img, i, j, argb_to_hex(color->v_color));
//             i++;
//         }
//         j++;
//     }
//     mlx_loop(mlx);
//     return (0);

    
// }

int		raytracing(t_scene *scene, t_garbage_collector *gc)
{
    t_camera *cam;
    t_vector *pixel_center;
    t_vector *ray_direction;
    t_ray *ray;
    t_sphere *sphere;
    t_vector *v1;
    t_vector *v2;
    t_vector *v3;
    t_cylinder *cy;
    int h;
    setup_sphere(&(scene->spheres[0]));
    printf("number of spheres = %d\n", scene->nr_spheres);

    cam = init_camera(init_vector(0,0,0,gc), NULL, 60, gc);
    cy = init_cylinder(init_vector(0,0,300, gc), init_vector(0,0,1, gc),  14.2,  150, init_vector(0,255,0, gc), gc);
    // printf("cylinder_point (%f , %f, %f) \n", cy->point->coordinate[0],cy->point->coordinate[1],cy->point->coordinate[2]);

    sphere = init_sphere(init_vector(0,0,cam->distance + HEIGHT,gc), HEIGHT, init_vector(255,0,0,gc), gc);
    // cam->distance = 1.0;
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
    int r = 0;
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
            v1 = vector_sum(init_vector(i,0,0,gc), init_vector(0,-j,0,gc), gc);
            // printf("cam_rad = (%f,%f,%f)\n", cam->radius->coordinate[0], cam->radius->coordinate[1], cam->radius->coordinate[2]);
            v2 = vector_sum(cam->radius, v1, gc);
            // printf("v1 = (%f,%f,%f)\n", v1->coordinate[0], v1->coordinate[1], v1->coordinate[2]);
            // printf("v2 = (%f,%f,%f)\n", v2->coordinate[0], v2->coordinate[1], v2->coordinate[2]);
            ray_direction = vector_sum(cam->o_vp, v2, gc);
            // printf("ray_dir = (%f,%f,%f)\n", ray_direction->coordinate[0], ray_direction->coordinate[1], ray_direction->coordinate[2]);
            // if(i == 1)
            //     return 0;
            // printf(" r[0] = %f ; r[1] = %f ; r[2] = %f\n", ray_direction->coordinate[0],ray_direction->coordinate[1],ray_direction->coordinate[2] );
            ray = init_ray(cam->point, ray_direction, gc);
            // printf("ray_or = (%f,%f,%f)\n", ray->origin->coordinate[0], ray->origin->coordinate[1], ray->origin->coordinate[2]);
            color = init_color(init_vector(0, 0 , 255, gc), ray_direction, gc);
            	mlx_put_pixel(img, i, j, argb_to_hex(color->v_color));
            h = 0;
            while (h < scene->nr_spheres)
            {
                
                if(hit_sphere(scene->spheres[h], ray, gc) != -1.0)
                {   
                    mlx_put_pixel(img, i, j, argb_to_hex(scene->spheres[h]->color));
                }
             
                h++;
            }
                // printf("num sphere = %d\n", scene->nr_spheres);
            
            //  if(hit_cylinder(cy, ray, gc))
            //     mlx_put_pixel(img, i, j, argb_to_hex(cy->color));
            // else if(hit_sphere(sphere, ray, gc) != -1.0)
            //     mlx_put_pixel(img, i, j, argb_to_hex(sphere->color));
			// else
			// 	mlx_put_pixel(img, i, j, argb_to_hex(color->v_color));
            i++;
        }
        j++;
    }
    i--;
    j--;
    mlx_loop(mlx);
    // return (0);

    
}
