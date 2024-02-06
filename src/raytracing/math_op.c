/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:12:20 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/06 04:55:42 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_vector *scalar_product(t_vector *v, double scalar, t_garbage_collector *gc)
{
    int i = 0;
    t_vector    *aux = init_vector(0,0,0, gc);

    while(i < 3){
        aux->coordinate[i] = v->coordinate[i] * scalar;
        i++;
    }
    return (aux);

}
t_vector *scalar_division(t_vector *v, double scalar, t_garbage_collector *gc)
{
    int i = 0;
    t_vector    *aux = init_vector(0,0,0, gc);

    while(i < 3){
        aux->coordinate[i] = v->coordinate[i] / scalar;
        i++;
    }
    return (aux);
}

t_vector    *vector_difference(t_vector *v1, t_vector *v2, t_garbage_collector *gc)
{
    t_vector    *aux = init_vector(0,0,0, gc);
    aux = init_vector( v1->coordinate[0] - v2->coordinate[0], \
                     v1->coordinate[1] - v2->coordinate[1], \
                     v1->coordinate[2] - v2->coordinate[2] , gc);
    return (aux);

}
t_vector    *vector_sum(t_vector *v1, t_vector *v2, t_garbage_collector *gc)
{
    t_vector    *aux = init_vector(0,0,0, gc);
    aux = init_vector( v1->coordinate[0] + v2->coordinate[0], \
                     v1->coordinate[1] + v2->coordinate[1], \
                     v1->coordinate[2] + v2->coordinate[2] , gc);
    return (aux);
}

double	vector_vector(t_vector *v1, t_vector *v2)
{
	double	a;

	a = v1->coordinate[0] * v2->coordinate[0] + v1->coordinate[1]
		* v2->coordinate[1] + v1->coordinate[2] * v2->coordinate[2];
	return (a);
}

t_vector *normalize_vector(t_vector *v) {
    double length = sqrt(v->coordinate[0] * v->coordinate[0] +
                         v->coordinate[1] * v->coordinate[1] +
                         v->coordinate[2] * v->coordinate[2]);

    v->coordinate[0] /= length;
    v->coordinate[1] /= length;
    v->coordinate[2] /= length;


    return v;
}
