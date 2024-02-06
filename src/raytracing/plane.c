/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:25:05 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/06 05:51:23 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#define EPSILON 1e-6
// I need to do this paper , but for is good

// t_vec	x;
// 	t_vec	normal;
// 	double	t;
// 	double	b;
// 	double	a;

// 	normal = get_normalized(pl->dir);
// 	x = sub_vec(ray->origin, pl->cen);
// 	b = dot_product(ray->dir, normal);
// 	if (b != 0)
// 	{
// 		a = dot_product(x, normal);
// 		t = -a / b;
// 		if (t < EPS)
// 			return (-1.0);
// 		return (t);
// 	}
// 	return (-1.0);
// }

double hit_plane(t_plane *plane, t_ray *ray, t_garbage_collector *gc)
{
    plane->normal_vector = normalize_vector(plane->normal_vector);
    // Calcula el vector desde el origen del rayo hasta el punto del plano
   t_vector *oc = init_vector(ray->origin->coordinate[0] - plane->point->coordinate[0],
                            ray->origin->coordinate[1] - plane->point->coordinate[1],
                            ray->origin->coordinate[2] - plane->point->coordinate[2], gc);


    // Normaliza el vector de dirección del rayo
//    ray->direction= normalize_vector(ray->direction);
    // printf("plane_normal(%f , %f, %f) \n", plane->normal_vector->coordinate[0],plane->normal_vector->coordinate[1],plane->normal_vector->coordinate[2]);
    // printf("ray_dir(%f , %f, %f) \n", ray->direction->coordinate[0],ray->direction->coordinate[1],ray->direction->coordinate[2]);


    double denominator = vector_vector(ray->direction, plane->normal_vector);

        //  printf("denominator = %f\n", denominator);
        //  exit(1);
    // Verifica si el rayo es paralelo o casi paralelo al plano
    // if (fabs(denominator) < 1e-6) {
    //     return -1.0;  // No hay intersección o el rayo está en el plano
    // }
    if (denominator != 0)
    {
        double a = vector_vector(oc, plane->normal_vector);
        double t = -a / denominator;
        // printf("a = %f\n", t);
        // printf("t = %f\n", t);
        // exit(1);
    // Verifica si el punto de intersección está frente al rayo
        if (t < EPSILON)
            return -1.0;  // No hay intersección o la intersección está detrás del rayo
        return t;
    }
    return (-1.0);

}
