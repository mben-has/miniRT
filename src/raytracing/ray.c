/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:19:11 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/06 01:29:59 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_ray *init_ray(t_vector *origin, t_vector *direction, t_garbage_collector *gc)
{
	t_ray *aux; 
    
    aux = malloc(sizeof(t_ray));
    if (!aux)
		exit_function(gc, "error while init ray\n", 1, true);
	else
		add_pointer_node(gc, aux);
	aux->direction = direction;
	aux->origin = origin;
	aux->clo = NULL;
	return (aux);
}

t_object *init_clo(char id, void **object, double distance, t_garbage_collector *gc)
{
	t_object *clo;
	t_sphere *sphere;
	t_cylinder *cylinder;
	
	clo = malloc(sizeof(t_object));
	if (!clo)
		exit_function(gc, "error while alloc closest_ob\n", 1, true);
	else
		add_pointer_node(gc, clo);
	if (id == 's')
	{
		sphere = (t_sphere *)(*object);
		clo_set_sp(&clo, &sphere, distance);
	}
	else if (id == 'c')
	{
		cylinder = (t_cylinder *)(*object);
		clo_set_cy(&clo, &cylinder, distance);
	}
	// else if (id == 'p')
	// 	//clo_set_pl(&clo);
	return (clo);
}

void clo_set_sp(t_object **object, t_sphere **sphere, double distance)
{
	(*object)->id = 's';
	(*object)->distance = distance;
	(*object)->sphere = (*sphere);
	(*object)->color = (*sphere)->color;
	// (*object)->cylinder = NULL;
	// (*object)->plane = NULL;

}
void clo_set_cy(t_object **object, t_cylinder **cylinder, double distance)
{
	(*object)->id = 'c';
	(*object)->distance = distance;
	(*object)->cylinder = (*cylinder);
	(*object)->color = (*cylinder)->color;
	// (*object)->sphere = NULL;
	// (*object)->plane = NULL;
}
