/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:23:55 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/15 07:16:43 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"
#include <stdarg.h>


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
	aux->direction = normalize(aux->direction, gc);
	return (aux);
}

t_vector *position(t_ray *ray, double t, t_garbage_collector *gc)
{
	t_vector *position;

	position = scalar_mult(ray->direction, t, gc);
	position = vector_add(ray->origin, position, gc);
	return (position);
}

t_intersections intersect_world(t_world *world, t_ray *r, t_garbage_collector *gc)
{
	int i;
	t_intersections xs;
	t_intersections aux;
	int j;
	int k;
	xs.count = 0;
	aux.count = 0;
	k = 0;  
	i = 0;
	while (i < world->nr_objects)
	{
		aux = intersect(world->objects[i], r, gc);
		if (aux.count > 0)
		{
			j = 0;
			while (j < aux.count)
			{
				xs.count++;
				xs.xs[k] = aux.xs[j];
				k++;
				j++;
			}
		}
		i++;
	}
	return (xs);
}

t_intersections intersect(t_object o, t_ray *r, t_garbage_collector *gc)
{
	t_intersections xs;
	if (o.id == 's')
		xs = intersect_sphere(o.sphere, r, gc);
	else if (o.id == 'c')
		printf("intersection cylinder not done yet\n");
	else if (o.id == 'p')
		xs = intersect_plane(o, r, gc);
	return(xs);
}

t_intersections intersect_sphere(t_sphere *s, t_ray *r, t_garbage_collector *gc)
{
	// print_matrix(s->transformation_matrix);
	t_intersections xs;
	t_ray *r2 = transform(r, inverse(s->transformation_matrix, gc), gc);
	t_vector *sphere_to_ray;
	double a, b, c, discriminant;
	double t1, t2;
	
	sphere_to_ray = vector_subtract(r2->origin, point(0,0,0,gc), gc);
	
	a = dot(r2->direction, r2->direction);
	
	b = 2 * dot(r2->direction, sphere_to_ray);

	c = dot(sphere_to_ray, sphere_to_ray) - 1;

	discriminant =  (b*b) - (4 * a * c);
	
	  if (discriminant < 0) {
			xs.count = 0;
			return(xs);
    }
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	xs = intersections(intersection(t1, s, gc), intersection(t2, s, gc), NULL);
return(xs);
}

/*
Testloesung von Mara, soll nicht so bleiben!!!
*/
t_intersections intersect_plane(t_object object, t_ray *r, t_garbage_collector *gc)
{
	t_intersections xs;
	t_intersection	inters;
	double			t;

	if (abs(r->origin->dim[1] < EPSILON))
	{
		xs.count = 0;
		return (xs);
	}
	t = -r->origin->dim[1] / r->direction->dim[1];
	inters.t = t;
	// printf("%f\n", t);
	t_object *obj = malloc(sizeof(t_object));
	inters.object = obj;
	inters.object->id = 'p';
	inters.object->sphere = NULL;
	inters.object->cylinder = NULL;
	inters.object->plane = object.plane;
	xs = intersections(inters, NULL);
	return(xs);
}

t_intersection intersection(double t, t_sphere *s, t_garbage_collector *gc)
{
	t_intersection i;
	
	i.t = t;
    i.object = (t_object *)malloc(sizeof(t_object));
	if (!i.object)
		exit_function(gc, "error alloc obj\n", 1, true);
	else
		add_pointer_node(gc, i.object);
	i.object->sphere = s;
	i.object->id = 's';
	i.object->plane = NULL;
	i.object->cylinder = NULL;
	return(i);
}

t_intersections intersections(t_intersection first, ...)
{
    va_list args;
    t_intersections intersections;
	t_intersection next;
    
    intersections.count = 1;
    intersections.xs[0] = first; 
    
    va_start(args, first);
    while (1)
    {
        next = va_arg(args, t_intersection);
        if (next.object == NULL) 
            break;
        intersections.xs[intersections.count] = next; 
		intersections.count++;
    }
    va_end(args);
    
    return (intersections);
}

t_intersection hit(t_intersections xs, double focal_length)
{
	t_intersection i;
	int j;
	double t;
	
	i.object = NULL;
	j = 0;
	while (j < xs.count)
	{
		if (xs.xs[j].t >=1)
		{
			t = xs.xs[j].t;
			i = xs.xs[j];
			j++;
			break;
		}
		j++;
	}
	while (j < xs.count)
	{
		if (xs.xs[j].t <= t  && xs.xs[j].t >=1)
		{
			t = xs.xs[j].t;
			i = xs.xs[j];
		}
		j++;
	}
	return (i);
}

t_ray *transform(t_ray *r, t_matrix *m, t_garbage_collector *gc)
{
	t_ray	*r2;
	
	r2 = ray(point(0,0,0,gc), vector(0,0,0,gc), gc);
    r2->origin->dim[0] = (*m)[0][0] * r->origin->dim[0] + (*m)[0][1] * r->origin->dim[1] + (*m)[0][2] * r->origin->dim[2] + (*m)[0][3];
    r2->origin->dim[1] = (*m)[1][0] * r->origin->dim[0] + (*m)[1][1] * r->origin->dim[1] + (*m)[1][2] * r->origin->dim[2] + (*m)[1][3];
    r2->origin->dim[2] = (*m)[2][0] * r->origin->dim[0] + (*m)[2][1] * r->origin->dim[1] + (*m)[2][2] * r->origin->dim[2] + (*m)[2][3];

    r2->direction->dim[0] = (*m)[0][0] * r->direction->dim[0] + (*m)[0][1] * r->direction->dim[1] + (*m)[0][2] * r->direction->dim[2];
    r2->direction->dim[1] = (*m)[1][0] * r->direction->dim[0] + (*m)[1][1] * r->direction->dim[1] + (*m)[1][2] * r->direction->dim[2];
    r2->direction->dim[2]= (*m)[2][0] * r->direction->dim[0] + (*m)[2][1] * r->direction->dim[1] + (*m)[2][2] * r->direction->dim[2];
    
    return r2;
}

void set_transform(t_sphere *s, t_matrix *m, t_garbage_collector *gc)
{
	int i = 0;
	int j = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			(*s->transformation_matrix)[i][j] = (*m)[i][j];
			j++;
		}
		i++;
	}
}

void print_matrix(t_matrix *m)
{
	int	k = 0;
	int l = 0;
	while(k < 4)
	{
		l = 0;
		while(l < 4)
		{
			printf("| %f | ", (*m)[k][l]);
			l++;
		}
		printf("\n");
		k++;
	}
}