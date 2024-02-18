/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:23:55 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/18 03:08:19 by mben-has         ###   ########.fr       */
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
	// aux->direction = normalize(aux->direction, gc);
	return (aux);
}

t_vector *position(t_ray *ray, double t, t_garbage_collector *gc)
{
	t_vector *position;

	position = scalar_mult(ray->direction, t, gc);
	position = vector_add(ray->origin, position, gc);
	return (position);
}
void sort_intersections(t_intersections *xs) 
{
    int i;
	int j;
	 t_intersection temp;

	i = 0;
    while (i < xs->count - 1) 
	{
         j = 0;
        while (j < xs->count - i - 1)
		 {
            if (xs->xs[j].t > xs->xs[j + 1].t) 
			{
                temp = xs->xs[j];
                xs->xs[j] = xs->xs[j + 1];
                xs->xs[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
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
	sort_intersections(&xs);
	return (xs);
}

t_intersections intersect(t_object o, t_ray *r, t_garbage_collector *gc)
{
	t_intersections xs;
	if (o.id == 's')
		xs = intersect_sphere(o, r, gc);
	else if (o.id == 'c')
		xs = intersect_cylinder(o, r, gc);
	else if (o.id == 'p')
		xs = intersect_plane(o, r, gc);
	return(xs);
}

t_intersections intersect_sphere(t_object o, t_ray *r, t_garbage_collector *gc)
{
	// print_matrix(s->transformation_matrix);
	t_sphere * s = o.sphere;
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
	xs = intersections(intersection(t1, o, gc), intersection(t2, o, gc), NULL);
return(xs);
}

/*
Testloesung von Mara, soll nicht so bleiben!!!
*/
t_intersections intersect_plane(t_object o, t_ray *r, t_garbage_collector *gc)
{
	t_intersections xs;
	t_intersection	inters;
	double			t;

	t_matrix *m = inverse(o.plane->transformation_matrix, gc);
	t_ray *r2 = transform(r, m, gc);
	if (abs(r2->origin->dim[1]) < EPSILON)
	{
		xs.count = 0;
		// printf("%f\n", abs(r2->origin->dim[1]));
		return (xs);
	}
	t = (-r2->origin->dim[1]) / (r2->direction->dim[1]);
	// inters.t = t;
	// t_object *obj = malloc(sizeof(t_object));
	// inters.object = obj;
	// inters.object->id = 'p';
	// inters.object->sphere = NULL;
	// inters.object->cylinder = NULL;
	// inters.object->plane = object.plane;
	xs = intersections(intersection(t, o, gc), NULL);
	return(xs);
}

t_intersection intersection(double t, t_object object, t_garbage_collector *gc)
{
	t_intersection i;
	
	if(object.id == 's')
	{
		i.t = t;
		i.object = (t_object *)malloc(sizeof(t_object));
		if (!i.object)
			exit_function(gc, "error alloc obj\n", 1, true);
		else
			add_pointer_node(gc, i.object);
		i.object->sphere = object.sphere;
		i.object->id = 's';
		i.object->plane = NULL;
		i.object->cylinder = NULL;
	}
	else if(object.id == 'p')
	{
		i.t = t;
		i.object = (t_object *)malloc(sizeof(t_object));
		if (!i.object)
			exit_function(gc, "error alloc obj\n", 1, true);
		else
			add_pointer_node(gc, i.object);
		i.object->plane = object.plane;
		i.object->id = 'p';
		i.object->sphere = NULL;
		i.object->cylinder = NULL;
	}
	else if(object.id == 'c')
	{
		i.t = t;
		i.object = (t_object *)malloc(sizeof(t_object));
		if (!i.object)
			exit_function(gc, "error alloc obj\n", 1, true);
		else
			add_pointer_node(gc, i.object);
		i.object->plane = NULL;
		i.object->id = 'c';
		i.object->sphere = NULL;
		i.object->cylinder =  object.cylinder;
	}
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
		if (xs.xs[j].t >=0)
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
		if (xs.xs[j].t <= t  && xs.xs[j].t >=0)
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


#define EPSILON 1e-6 // Umbral de tolerancia

int approximately_equal(double a, double b) {
    return fabs(a - b) < EPSILON;
}

t_vector *local_normal_at(t_cylinder *cy, t_vector *point, t_garbage_collector *gc)
{
    double dist = point->dim[0] * point->dim[0] + point->dim[2] * point->dim[2];
    
    if (dist < 1 && approximately_equal(point->dim[1], cy->maximum - EPSILON)) {
        return vector(0, 1, 0,gc);
    } else if (dist < 1 && approximately_equal(point->dim[1], cy->minimum + EPSILON)) {
        return vector(0, -1, 0,gc);
    } else {
        return vector(point->dim[0], 0, point->dim[2],gc);
    }
}
int check_cap(t_ray *ray, double t)
{
    double x = ray->origin->dim[0] + t * ray->direction->dim[0];
    double z = ray->origin->dim[2] + t * ray->direction->dim[2];
    
    if ((x * x + z * z) <= 1.0) {
        return 1; // El punto está dentro del círculo
    } else {
        return 0; // El punto está fuera del círculo
    }
}

void intersect_caps(t_object* o, t_ray *ray, t_intersections *xs, t_garbage_collector *gc) {

	t_cylinder *cyl = (*o).cylinder;
    // Los extremos solo importan si el cilindro está cerrado y podría ser
    // intersectado por el rayo.
    if (approximately_equal(ray->direction->dim[1], 0.0)) {
        return;
    }

    // Comprueba si hay una intersección con el extremo inferior
    // al intersectar el rayo con el plano en y=cyl.minimum
    double t = (cyl->minimum - ray->origin->dim[1]) / ray->direction->dim[1];
    if (check_cap(ray, t)) {
        (*xs).xs[(*xs).count++] = intersection(t, *o, gc);
    }

    // Comprueba si hay una intersección con el extremo superior
    // al intersectar el rayo con el plano en y=cyl.maximum
    t = (cyl->maximum - ray->origin->dim[1]) / ray->direction->dim[1];
    if (check_cap(ray, t)) {
       (*xs).xs[(*xs).count++] = intersection(t, *o, gc);
    }
}

t_intersections intersect_cylinder(t_object o, t_ray *ray, t_garbage_collector *gc)
{
	
	t_cylinder *cy = o.cylinder;
    t_intersections xs;
    double a, b, c, disc, t0, t1;
	t_ray *r = transform(ray, inverse(cy->transformation_matrix, gc), gc);
    
    // Calcula a
	// a ← ray.direction.x² + ray.direction.z²
    a = r->direction->dim[0] * r->direction->dim[0] + r->direction->dim[2] * r->direction->dim[2];
    
    // Verifica si el ro es paralelo al eje y
    if (approximately_equal(a, 0.0)) {
        xs.count = 0;
        return xs;
    }

    b = 2 * (r->origin->dim[0] * r->direction->dim[0] + r->origin->dim[2] * r->direction->dim[2]);


    c = r->origin->dim[0] * r->origin->dim[0] + r->origin->dim[2] * r->origin->dim[2] - 1;
    
    // Calcula el discriminante
	// disc ← b² - 4 * a * c
    disc = b * b - 4 * a * c;
    
    // Verifica si el ro no intersecta el cilindro
    if (disc < 0) {
        xs.count = 0;
        return xs;
    }
    
    t0 = (-b - sqrt(disc)) / (2 * a);
    t1 = (-b + sqrt(disc)) / (2 * a);
    
	if (t0 > t1) {
    double temp = t0;
    t0 = t1;
    t1 = temp;
}

 xs.count = 0;
    intersect_caps(&o, r, &xs,gc);

   double y0 = r->origin->dim[1] + t0 * r->direction->dim[1];
    if (cy->minimum < y0 && y0 < cy->maximum) {
        xs.xs[xs.count++] = intersection(t0, o, gc);
    }
    
    // Calcula y1 y verifica si está dentro del rango
    double y1 = r->origin->dim[1] + t1 * r->direction->dim[1];
    if (cy->minimum < y1 && y1 < cy->maximum) {
        xs.xs[xs.count++] = intersection(t1, o, gc);
    }

    return xs;
}
