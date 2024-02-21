/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:09:26 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 15:24:39 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

t_color	*get_black(t_garbage_collector *gc)
{
	t_color	*col;

	col = color(0.0, 0.0, 0.0, gc);
	return (col);
}

t_computation	*prepare_computations(t_intersection *intersection, \
	t_ray *ray, t_light light, t_garbage_collector *gc)
{
	t_computation	*comp;

	comp = (t_computation *) malloc(sizeof(t_computation));
	if (comp == NULL)
		exit_function(gc, "malloc fail\n", 1, true);
	else
		add_pointer_node(gc, comp);
	prepare_computations_1(comp, intersection, ray, gc);
	prepare_computations_2(comp, light, gc);
	return (comp);
}

t_color	*shade_hit(t_world *world, t_computation *computation, \
	t_garbage_collector *gc)
{
	bool	shadowed;

	shadowed = is_shadowed(world, computation->over_point, gc);
	return (lighting(computation, shadowed, gc));
}

t_color	*color_at(t_world *world, t_ray *ray, t_garbage_collector *gc)
{
	t_intersections	intersections;
	t_intersection	intersection;
	t_computation	*computation;
	t_color			*col;

	intersections = intersect_world(world, ray, gc);
	intersection = hit(intersections, ray->original_length);
	if (intersection.object == NULL)
		return (get_black(gc));
	computation = prepare_computations(&intersection, ray, world->light, gc);
	col = shade_hit(world, computation, gc);
	return (col);
}
