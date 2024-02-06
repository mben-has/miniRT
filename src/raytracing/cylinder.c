/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:16:57 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/06 12:00:22 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

// t_cylinder *init_cylinder(t_vector *point, t_vector *axis, double diameter, double height, t_vector *color, t_garbage_collector *gc)
// {
//     t_cylinder *cy;

   
//     cy = malloc(sizeof(t_cylinder));
// 	if (!cy)
//         exit_function(gc, "error while init cylinder\n", 1, true);
//     else
//         add_pointer_node(gc, cy);
//     cy->point = init_vector(point->coordinate[0], point->coordinate[1], point->coordinate[2], gc);
//     cy->axis_vector =init_vector(axis->coordinate[0], axis->coordinate[1], axis->coordinate[2], gc);
//     cy->diameter = diameter;
//     cy->height = height;
//     cy->color = init_vector(color->coordinate[0], color->coordinate[1], color->coordinate[2], gc);;
//     return (cy);
// }

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

// double check_intersections(t_ray **ray, t_cylinder **cylinder, int a,  double b , double c)
// {     double t1;
//      double t2;
//       t1 = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);
//      t2 = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);

//     if (((*ray)->origin->coordinate[1] + t1 * (*ray)->direction->coordinate[1] >= -(*cylinder)->height / 2.0 &&
//          (*ray)->origin->coordinate[1] + t1 * (*ray)->direction->coordinate[1] <= (*cylinder)->height / 2.0) ||
//         ((*ray)->origin->coordinate[1] + t2 * (*ray)->direction->coordinate[1] >= -(*cylinder)->height / 2.0 &&
//          (*ray)->origin->coordinate[1] + t2 * (*ray)->direction->coordinate[1] <= (*cylinder)->height / 2.0)) {
//         // Devolver el punto de intersección más cercano
//        if (t1 < t2) {
//             return t1;
//         } else {
//             return t2;
//         }
//     }
//     else 
//         return (-1.0);
// }
// double hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_garbage_collector *gc)
// {
//      double a;
//      double b ;
//      double c;
//     t_vector *oc;
     
//     oc = vector_difference(ray->origin, cylinder->point, gc);
//     a = ray->direction->coordinate[0] * ray->direction->coordinate[0] + ray->direction->coordinate[2] * ray->direction->coordinate[2];
//      b = 2.0 * (oc->coordinate[0] * ray->direction->coordinate[0] + oc->coordinate[2] * ray->direction->coordinate[2]);
//     c = oc->coordinate[0] * oc->coordinate[0] + oc->coordinate[2] * oc->coordinate[2] - (cylinder->diameter / 2.0 * cylinder->diameter / 2.0);

//     if (b * b - 4 * a * c < 0)
//         return -1.0;  // No hay intersección
     
//     // Verificar intersección con los extremos del cilindro
//    return check_intersections(&ray, &cylinder, a, b , c);

//     // return  (check_intersections(ray,cylinder, a, b , c));  // No hay intersección con los extremos
   
// }

// double hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_garbage_collector *gc)
// {
//     t_vector *oc = vector_difference(ray->origin, cylinder->point, gc);
//     double a = ray->direction->coordinate[0] * ray->direction->coordinate[0] + ray->direction->coordinate[2] * ray->direction->coordinate[2];
//     double b = 2.0 * (oc->coordinate[0] * ray->direction->coordinate[0] + oc->coordinate[2] * ray->direction->coordinate[2]);
//     double c = oc->coordinate[0] * oc->coordinate[0] + oc->coordinate[2] * oc->coordinate[2] - (cylinder->diameter / 2.0 * cylinder->diameter / 2.0);

//     if (b * b - 4 * a * c < 0)
//         return -1.0;  // No hay intersección

//     // Verificar intersección con los extremos del cilindro
//     double t1 = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);
//     double t2 = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);

//     if ((ray->origin->coordinate[1] + t1 * ray->direction->coordinate[1] >= -cylinder->height / 2.0 &&
//          ray->origin->coordinate[1] + t1 * ray->direction->coordinate[1] <= cylinder->height / 2.0) ||
//         (ray->origin->coordinate[1] + t2 * ray->direction->coordinate[1] >= -cylinder->height / 2.0 &&
//          ray->origin->coordinate[1] + t2 * ray->direction->coordinate[1] <= cylinder->height / 2.0)) {
//         // Devolver el punto de intersección más cercano
//         return (t1 < t2) ? t1 : t2;
//     }

//     return -1.0;  // No hay intersección con los extremos
// }

#include <math.h>

#include <math.h>

#include <math.h>

double hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_garbage_collector *gc)
{
    // Ensure that the axis vector is normalized
    double axis_length = sqrt(cylinder->axis_vector->coordinate[0] * cylinder->axis_vector->coordinate[0] +
                               cylinder->axis_vector->coordinate[1] * cylinder->axis_vector->coordinate[1] +
                               cylinder->axis_vector->coordinate[2] * cylinder->axis_vector->coordinate[2]);
    if (fabs(axis_length - 1.0) > 1e-6) {
        // If the axis vector is not normalized, return -1.0 indicating no intersection
        return -1.0;
    }

    // Transform the ray and cylinder to align with the cylinder's axis
    t_vector *oc = vector_difference(ray->origin, cylinder->point, gc);
    double dot_product =vector_vector(oc, cylinder->axis_vector);
    t_vector *oc_parallel = scalar_product(cylinder->axis_vector, dot_product, gc);
    t_vector *oc_perpendicular = vector_difference(oc, oc_parallel, gc);

    double a = vector_vector(ray->direction, ray->direction) - pow(vector_vector(ray->direction, cylinder->axis_vector), 2);
    double b = 2.0 * (vector_vector(ray->direction, oc_perpendicular) - vector_vector(ray->direction, cylinder->axis_vector) * vector_vector(oc_perpendicular, cylinder->axis_vector));
    double c = vector_vector(oc_perpendicular, oc_perpendicular) - pow(vector_vector(oc_perpendicular, cylinder->axis_vector), 2) - pow(cylinder->diameter / 2.0, 2);

    // Calculate the discriminant of the quadratic equation
    double discriminant = b * b - 4 * a * c;

    // Check if there is no intersection (negative discriminant)
    if (discriminant < 0)
        return -1.0;

    // Calculate the two possible solutions of the quadratic equation
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);

    // Calculate the y coordinate of the intersection points with the ends of the cylinder
    double y1 = vector_vector(vector_sum(ray->origin, scalar_product(ray->direction, t1, gc), gc), cylinder->axis_vector);
    double y2 = vector_vector(vector_sum(ray->origin, scalar_product(ray->direction, t2, gc), gc), cylinder->axis_vector);

    // Check if any of the intersections are within the height range of the cylinder
    if ((y1 >= -cylinder->height / 2.0 && y1 <= cylinder->height / 2.0) ||
        (y2 >= -cylinder->height / 2.0 && y2 <= cylinder->height / 2.0)) {
        // Return the nearest intersection point (the smaller of t1 and t2)
        return (t1 < t2) ? t1 : t2;
    }

    // If no intersection is within the height range, there is no intersection
    return -1.0;
}


