/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:23:27 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:11 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"
#include <stdarg.h>

t_intersections	intersect_plane(t_object o, t_ray *r2, t_garbage_collector *gc)
{
	t_intersections	xs;
	double			t;

	if (fabs(r2->origin->dim[1]) < EPSILON)
	{
		xs.count = 0;
		return (xs);
	}
	t = (-r2->origin->dim[1]) / (r2->direction->dim[1]);
	xs = intersections(intersection(t, o, gc), NULL);
	return (xs);
}

t_intersection	intersection_plane(double t, t_object *object,
		t_garbage_collector *gc)
{
	t_intersection	i;

	i.t = t;
	i.object = (t_object *)malloc(sizeof(t_object));
	if (!i.object)
		exit_function(gc, "error alloc obj\n", 1, true);
	else
		add_pointer_node(gc, i.object);
	i.object->plane = (*object).plane;
	i.object->id = 'p';
	i.object->sphere = NULL;
	i.object->cylinder = NULL;
	return (i);
}
