/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:16:57 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/06 00:42:02 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_cylinder *init_cylinder(t_vector *point, t_vector *axis, double diameter, double height, t_vector *color, t_garbage_collector *gc)
{
    t_cylinder *cy;

   
    cy = malloc(sizeof(t_cylinder));
	if (!cy)
        exit_function(gc, "error while init cylinder\n", 1, true);
    else
        add_pointer_node(gc, cy);
    cy->point = init_vector(point->coordinate[0], point->coordinate[1], point->coordinate[2], gc);
    cy->axis_vector =init_vector(axis->coordinate[0], axis->coordinate[1], axis->coordinate[2], gc);
    cy->diameter = diameter;
    cy->height = height;
    cy->color = init_vector(color->coordinate[0], color->coordinate[1], color->coordinate[2], gc);;
    return (cy);
}

// bool hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_garbage_collector *gc)
// {
//     t_vector *oc = vector_difference(ray->origin, cylinder->point, gc);
//     double a = ray->direction->coordinate[0] * ray->direction->coordinate[0] + ray->direction->coordinate[2] * ray->direction->coordinate[2];
//     double b = 2.0 * (oc->coordinate[0] * ray->direction->coordinate[0] + oc->coordinate[2] * ray->direction->coordinate[2]);
//     double c = oc->coordinate[0] * oc->coordinate[0] + oc->coordinate[2] * oc->coordinate[2] - (cylinder->diameter / 2.0 * cylinder->diameter / 2.0);
//     double check_sqrt = b * b - 4 * a * c;

//     if (check_sqrt < 0)
//         return false;

//     // Verificar intersección con los extremos del cilindro
//     double t1 = (-b - sqrt(check_sqrt)) / (2.0 * a);
//     double t2 = (-b + sqrt(check_sqrt)) / (2.0 * a);

//     double y1 = ray->origin->coordinate[1] + t1 * ray->direction->coordinate[1];
//     double y2 = ray->origin->coordinate[1] + t2 * ray->direction->coordinate[1];

//     if ((y1 >= -cylinder->height / 2.0 && y1 <= cylinder->height / 2.0) ||
//         (y2 >= -cylinder->height / 2.0 && y2 <= cylinder->height / 2.0))
//         return true;

//     return false;
// }

double hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_garbage_collector *gc)
{
    t_vector *oc = vector_difference(ray->origin, cylinder->point, gc);
    double a = ray->direction->coordinate[0] * ray->direction->coordinate[0] + ray->direction->coordinate[2] * ray->direction->coordinate[2];
    double b = 2.0 * (oc->coordinate[0] * ray->direction->coordinate[0] + oc->coordinate[2] * ray->direction->coordinate[2]);
    double c = oc->coordinate[0] * oc->coordinate[0] + oc->coordinate[2] * oc->coordinate[2] - (cylinder->diameter / 2.0 * cylinder->diameter / 2.0);
    double check_sqrt = b * b - 4 * a * c;

    if (check_sqrt < 0)
        return -1.0;  // No hay intersección

    // Verificar intersección con los extremos del cilindro
    double t1 = (-b - sqrt(check_sqrt)) / (2.0 * a);
    double t2 = (-b + sqrt(check_sqrt)) / (2.0 * a);

    double y1 = ray->origin->coordinate[1] + t1 * ray->direction->coordinate[1];
    double y2 = ray->origin->coordinate[1] + t2 * ray->direction->coordinate[1];

    if ((y1 >= -cylinder->height / 2.0 && y1 <= cylinder->height / 2.0) ||
        (y2 >= -cylinder->height / 2.0 && y2 <= cylinder->height / 2.0)) {
        // Devolver el punto de intersección más cercano
        return (t1 < t2) ? t1 : t2;
    }

    return -1.0;  // No hay intersección con los extremos
}
