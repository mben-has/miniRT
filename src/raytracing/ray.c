/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:23:55 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/11 20:34:45 by mben-has         ###   ########.fr       */
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