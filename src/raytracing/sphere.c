/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:22:44 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/04 22:11:52 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_sphere *init_sphere(t_vector *position, double diameter, t_vector *color, t_garbage_collector *gc)
{
    t_sphere *sphere;

    sphere = malloc(sizeof(t_sphere));
    if(!sphere)
        return (NULL);
    else
        add_pointer_node(gc, sphere);
    sphere->point = position;
    sphere->diameter = diameter;
    sphere->radius = diameter * 0.5;
    sphere->color = init_vector(color->coordinate[0], color->coordinate[1], color->coordinate[2], gc);
    return (sphere);
}

double vector_vector(t_vector *v1, t_vector *v2)
{
    double a;

    a = v1->coordinate[0] * v2->coordinate[0] \
      + v1->coordinate[1] * v2->coordinate[1] \
      + v1->coordinate[2] * v2->coordinate[2];

    return (a);
}

bool hit_sphere(t_sphere *sphere, t_ray *ray, t_garbage_collector *gc)
{
    t_vector *oc = vector_difference(ray->origin, sphere->point, gc);
    double a = vector_vector(ray->direction, ray->direction);
    double b = 2.0 * vector_vector(oc, ray->direction);
    double c = vector_vector(oc, oc) - (sphere->radius * sphere->radius);
    double check_sqrt = b*b - 4*a*c;
    return (check_sqrt >= 0);
}