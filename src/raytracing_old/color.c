/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:08:10 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/06 09:10:24 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
// double  vector_dot_product( t_vector *v1, t_vector *v2){
//     double dotProduct;

//     dotProduct =   ( v1->coordinate[0] * v2->coordinate[0] + \
//                      v1->coordinate[1] * v2->coordinate[1] + \
// //                      v1->coordinate[2] * v2->coordinate[2] );
// //     return dotProduct;
// // }
    

// t_vector    *versor (t_vector *v, t_garbage_collector *gc)
// {
//     t_vector    *new;
//     double     lenght;

//     lenght = sqrt(v->coordinate[0] * v->coordinate[0] + v->coordinate[1] * v->coordinate[1] + v->coordinate[2] * v->coordinate[2]);
//     new = init_vector((v->coordinate[0])/lenght, (v->coordinate[1])/lenght, (v->coordinate[2])/lenght, gc);
//     return      new;
// }

// t_color *init_color(t_vector *colors, t_vector *ray_dir, t_garbage_collector *gc)
// {
//     t_color *color;
//     color = malloc(sizeof(t_color));
//     if (!color)
//         exit_function(gc, "error while alloc color", 1, true);
//     else
//         add_pointer_node(gc, color);
//     color->v_color = init_vector(colors->coordinate[0],\
//     colors->coordinate[1],\
//     colors->coordinate[2], gc);
//     t_vector *unit_direction = versor(ray_dir, gc);
//     double a = (unit_direction->coordinate[1] + 1.0) * 0.5;
//     // printf("double a = %f\n", a);
//     t_vector *color1 = init_vector(1.0, 1.0, 1.0, gc);
// 	t_vector *color2 = init_vector(0.5, 0.7, 1.0, gc);
//     color->v_color = vector_sum(scalar_product(color1,(1.0-a) *255, gc),scalar_product(color2,a * 255,gc),gc);   
//     // printf("u[0] = %f ; u[1] = %f ; r[2] = %f\n", color->v_color->coordinate[0],color->v_color->coordinate[1],color->v_color->coordinate[2] );
//     //return vector_summ(scalar_multiplication(color1,(1.0-a)), scalar_multiplication(color2,(a)));
//     return (color);
// }