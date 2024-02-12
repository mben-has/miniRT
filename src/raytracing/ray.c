/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:23:55 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/12 15:16:03 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"

t_ray *ray(t_vector *origin, t_vector *direction, t_garbage_collector *gc)
{
	t_ray *aux; 
    
    aux = malloc(sizeof(t_ray));
    if (!aux)
		exit_function(gc, "error while init ray\n", 1, true);
	else
		add_pointer_node(gc, aux);
	aux->direction = direction;
	aux->origin = origin;
	// aux->clo = NULL;
	// aux->direction = normalize_vector(aux->direction);
	return (aux);
}

t_vector *position(t_ray *ray, double t, t_garbage_collector *gc)
{
	t_vector *position;

	position = scalar_mult(ray->direction, t, gc);
	position = vector_add(ray->origin, position, gc);
	return (position);
}