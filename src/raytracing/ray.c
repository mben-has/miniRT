/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:19:11 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/06 08:48:26 by mben-has         ###   ########.fr       */
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
	aux->direction = normalize_vector(aux->direction);
	return (aux);
}
t_ray *get_ray(t_scene **scene, int i, int j, t_garbage_collector *gc)
{
    t_vector *ray_direction;
    t_ray *ray;
    t_vector *v1;
    t_vector *v2;

    v1 = vector_sum(init_vector(i + 0.5 ,0,0,gc), init_vector(0,-j -0.5,0,gc), gc);
    v2 = vector_sum((*scene)->camera.radius, v1, gc);
    ray_direction = vector_sum((*scene)->camera.o_vp, v2, gc);
    ray = init_ray((*scene)->camera.point, ray_direction, gc);
    return (ray);
}
t_object *init_clo(char id, void **object, double distance, t_garbage_collector *gc)
{
	t_object *clo;
	t_sphere *sphere;
	t_cylinder *cylinder;
	t_plane *plane;
	
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
	else if (id == 'p')
	{
		plane = (t_plane *)(*object);
		clo_set_pl(&clo, &plane, distance);
	}
	
	return (clo);
}

void clo_set_pl(t_object **object,t_plane **plane, double distance)
{
	(*object)->id = 'p';
	(*object)->distance = distance;
	(*object)->plane = (*plane);
	(*object)->color = (*plane)->color;
	// (*object)->cylinder = NULL;
	// (*object)->plane = NULL;

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
