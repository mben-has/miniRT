/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:40:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/15 08:08:07 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
#include "../../include/structure_rtc.h"

t_ray *get_ray(t_camera *cam, int i, int j, t_garbage_collector *gc)
{
	   t_vector *v1;
	   t_vector *vo;
	   t_vector *p;
		t_ray *r;

		vo = vector_subtract((*cam).pixel00, (*cam).point, gc);
	   v1 = vector_add( scalar_mult((*cam).v_width, i, gc) , scalar_mult((*cam).v_height,-j, gc), gc); 
	// printf("v1 coordinates (%f, %f, %f, %f) \n", v1->dim[0], v1->dim[1],v1->dim[2],v1->dim[3] );
	//    v1 = vector_add(v1, (*cam).pixel00, gc);
	   vo = vector_add(vo, v1, gc);
	// printf("*********************************************************************************\n");
	// printf("RAY coordinates (%f, %f, %f, %f) \n", vo->dim[0], vo->dim[1],vo->dim[2],vo->dim[3] );
    r = ray((*cam).point, vo, gc);
	//    p = point(0, 0 ,0, gc);
		// p->dim[0] = (*cam).pixel00[0] ;
    // t_vector *ray_direction;
    // t_ray *ray;
    // t_vector *v1;
    // t_vector *v2;

	// v1 = vector_subtract((*cam).pixel00, (*cam).point, gc);
    // v1 = vector_sum(init_vector(i + 0.5 ,0,0,gc), init_vector(0,-j -0.5,0,gc), gc);
    // v2 = vector_sum((*scene)->camera.radius, v1, gc);
    // ray_direction = vector_sum((*scene)->camera v2, gc);
	p = r->direction;
	// printf("%d %d : %f %f %f\n", i, j, p->dim[0], p->dim[1],p->dim[2]);
    return (r);
}

void	draw(t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	int			i;
	int			j;
	t_ray		*ray;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_color 	*color_vector;
	unsigned int	color_hex;
	t_intersections xs;
	t_intersection ht;

	i = 0;
	j = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "minirt", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray = get_ray(camera, i, j, gc);
			// xs = intersect_world(world, ray, gc);
			// ht = hit(xs, 0);
			// if (ht.object != NULL)
			// 	mlx_put_pixel(img, i, j, 0xFF0000FF);
			// if(ray->direction->dim[0] == 0 && ray->direction->dim[1] == 0)
			// {
			// 	printf("xs.count = %d \n", xs.count);	
			// 	printf("xs[0] = %f ; xs[1] = %f \n", xs.xs[0], xs.xs[1]);	
			// 	printf("t[0] = %f \n", ht.t);	
			// 	// printf("object = %c \n", t.object->id );	
			// 	return;
			// }
			
			color_vector = color_at(world, ray, gc);
			color_hex = rgb_to_hex(color_vector);
			mlx_put_pixel(img, i, j, color_hex);
			// if (check_hit(&(*scene), &ray, gc))
			// ray = ray();
			// ray = ray((*camera).point, ,gc);
			i++;
		}
		j++;
	}
	mlx_loop(mlx);
}

int	raytracing(t_world *world, t_camera *camera, t_garbage_collector *gc)
{

	printf("num of objects = %d\n", world->nr_objects);
	draw(world, camera, gc);

// t_sphere *s2 = world->objects[1].sphere;

// // t_material *scaled = scaling(point(0.5, 0.5, 0.5, gc),gc);
// // s2->transformation_matrix = matrix_mult_m(s2->transformation_matrix , scaled , gc);

// t_vector *v = vector (0, 0, 1, gc);
// t_vector *p = point(0, 0 , -5, gc);
// t_ray *r = ray (p, v , gc); 

// t_intersection  i = intersection(4, world->objects[1],gc);
// t_computation * c = prepare_computations(i , ray, world->light,gc);
// printf(" comps.t = %f", c.)
// t_intersections xs = intersect_world(world, r, gc);
 	// printf("xs.count = %d \n", xs.count);	
	// 			printf("xs[0] = %f ; xs[1] = %f ", xs.xs[0], xs.xs[1]);	
	// 			printf("xs[0] = %f ; xs[1] = %f \n", xs.xs[2], xs.xs[3]);	
				
	// int i = 0;
	// int num_spheres = 0;
	// while (i < world->nr_objects)
	// {
	// 	if(world->objects[0].id == 's')
	// 	{
	// 		s = world->objects[i].sphere;
	// 		print_matrix(s->transformation_matrix);
	// 		num_spheres++;

	// 	}
	// 	i++;z
	// }
// 	printf("num of spheres = %d\n", num_spheres);

// Scenario: Aggregating intersections
// Given s ← sphere()
// And i1 ← intersection(1, s)
// And i2 ← intersection(2, s)
// When xs ← intersections(i1, i2)
// Then xs.count = 2
// And xs[0].t = 1
// And xs[1].t = 2

// xs = intersections(intersection(1, s, gc), intersection(2, s, gc), NULL);

// printf("xs.count = %d\n", xs.count);
// printf("xs[0].t = %f\n", xs.xs[0].t);
// printf("xs[1].t = %f\n", xs.xs[1].t);
// printf("xs.id = %c\n", xs.xs[0].object->id);
// printf("xs.id = %c\n", xs.xs[1].object->id);


// Scenario: A sphere is behind a ray
// Given r ← ray(point(0, 0, 5), vector(0, 0, 1))
// And s ← sphere()
// When xs ← intersect(s, r)
// Then xs.count = 2
// And xs[0] = -6.0
// And xs[1] = -4.0
// t_vector *v = vector (0, 0, 1, gc);
// t_vector *p = point(0, 0 , 5, gc);
// // Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// t_ray *r = ray (p, v , gc); 
// // And s ← sphere()
// xs = intersect(s, r, gc);
// // Then xs.count = 2
// // And xs[0] = 4.0
// // And xs[1] = 6.0
// printf("xs.count = %d\n", xs->count);
// printf("xs[0] = %f\n", xs->xs[0].t);
// printf("xs[1] = %f\n", xs->xs[1].t);

	// (void)world;
	// (void)camera;

	// // draw(NULL, camera, gc);
	// Scenario: Computing a point from a distance

// // Given r ← ray(point(2, 3, 4), vector(1, 0, 0))
// t_vector * result;
// result = position(r, 0, gc); //= point(2, 3, 4)
// printf("result = (%f, %f, %f, %f)\n", result->dim[0], result->dim[1], result->dim[2], result->dim[3]);
// result = position(r, 1, gc);//point(3, 3, 4)
// printf("result = (%f, %f, %f, %f)\n", result->dim[0], result->dim[1], result->dim[2], result->dim[3]);
// result = position(r, -1, gc); //point(1, 3, 4)
// printf("result = (%f, %f, %f, %f)\n", result->dim[0], result->dim[1], result->dim[2], result->dim[3]);
// result = position(r, 2.5, gc); // point(4.5, 3, 4)
// printf("result = (%f, %f, %f, %f)\n", result->dim[0], result->dim[1], result->dim[2], result->dim[3]);

// Scenario: Intersect sets the object on the intersection
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And s ← sphere()
// When xs ← intersect(s, r)
// Then xs.count = 2
// And xs[0].object = s
// And xs[1].object = s

// t_vector *v = vector (0, 0, 1, gc);
// t_vector *p = point(0, 0 , -5, gc);
// t_ray *r = ray (p, v , gc); 
// t_intersections xs = intersect(s,r,gc);
// printf("xs.count = %d\n", xs.count);
// printf("xs[0] = %f\n", xs.xs[0].t);
// printf("xs[1] = %f\n", xs.xs[1].t);
// printf("id[0] = %c\n", xs.xs[0].object->id);
// printf("id[1] = %c\n", xs.xs[1].object->id);

// Scenario: The hit is always the lowest nonnegative intersection
// Given s ← sphere()
// And i1 ← intersection(5, s)
// And i2 ← intersection(7, s)
// And i3 ← intersection(-3, s)
// And i4 ← intersection(2, s)
// And xs ← intersections(i1, i2, i3, i4)
// When i ← hit(xs)

// t_intersection i1 = intersection(5, s, gc);
// t_intersection i2 = intersection(7, s, gc);
// t_intersection i3 = intersection(-3, s, gc);
// t_intersection i4 = intersection(2, s, gc);
// t_intersections xs = intersections(i2, i1, i3, i4, NULL);
// t_intersection h = hit(xs, (*camera).focal_length);
// printf("i1.t = %f\n", i1.t);
// printf("i2.t = %f\n", i2.t);
// printf("i3.t = %f\n", i3.t);
// printf("i4.t = %f\n", i4.t);
// printf("h.t = %f\n", h.t);
// printf("i1.id = %c\n", i1.object->id);
// printf("i2.id = %c\n", i2.object->id);
// printf("i3.id = %c\n", i3.object->id);
// printf("i4.id = %c\n", i4.object->id);
// if (h.object == NULL)
// 	printf("no object hitten\n");
// else
// 	printf("h.id = %c\n", h.object->id);
// Scenario: Scaling a ray
// Given r ← ray(point(1, 2, 3), vector(0, 1, 0))
// And m ← scaling(2, 3, 4)
// When r2 ← transform(r, m)
// Then r2.origin = point(2, 6, 12)
// And r2.direction = vector(0, 3, 0)
// t_vector *v = vector (0, 1, 0, gc);
// t_vector *p = point(1, 2, 3, gc);
// t_ray *r = ray (p, v , gc); 
// t_matrix *m = scaling(point(2, 3, 4, gc), gc);
// t_ray *r2 = transform(r, m, gc);
// printf("ray direction = (%f, %f, %f, %f)\n", r2->direction->dim[0], r2->direction->dim[1], r2->direction->dim[2], r2->direction->dim[3]);
// printf("ray origin = (%f, %f, %f, %f)\n", r2->origin->dim[0], r2->origin->dim[1], r2->origin->dim[2], r2->origin->dim[3]);
// printf("i4.id = %c\n", i4.object->id);
// Scenario: Changing a sphere's transformation
// Given s ← sphere()
// And t ← translation(2, 3, 4)
// t_matrix *t = translation(point(2,3,4, gc),gc);
// When set_transform(s, t)
// set_transform(s, t, gc);
// s->transformation_matrix = identity_matrix(gc);
// s->transformation_matrix = inverse(s->transformation_matrix,gc);

// i = 0;
// int j = 0;
// while(i < 4)
// {
// 	j = 0;
// 	while(j < 4)
// 	{
// 		printf("matrix[%d][%d] = %f \n", i, j, (*s->transformation_matrix)[i][j]);
// 		// printf("t[%d][%d] = %f \n", i, j, (*t)[i][j]);
// 		j++;
// 	}
// 	i++;
// }
// printf("im here 10\n");
// Scenario: Intersecting a scaled sphere with a ray
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And s ← sphere()
// When set_transform(s, scaling(2, 2, 2))
// And xs ← intersect(s, r)
// report erratum • discuss
// Transforming Rays and Spheres • 69
// Then xs.count = 2
// And xs[0].t = 3
// And xs[1].t = 7



// i = 0;
// int j = 0;
// while(i < 4)
// {
// 	j = 0;
// 	while(j < 4)
// 	{
// 		printf("matrix[%d][%d] = %f \n", i, j, (*s->transformation_matrix)[i][j]);
// 		// printf("t[%d][%d] = %f \n", i, j, (*t)[i][j]);
// 		j++;
// 	}
// 	i++;
// }

// Scenario: Intersecting a scaled sphere with a ray
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And s ← sphere()
// When set_transform(s, scaling(2, 2, 2))
// And xs ← intersect(s, r)
// report erratum • discuss
// Transforming Rays and Spheres • 69
// Then xs.count = 2
// And xs[0].t = 3
// And xs[1].t = 7

// t_matrix *m = scaling(point(2,2,2, gc), gc);
// set_transform(s, m, gc);
// i = 0;
// int j = 0;
// while(i < 4)
// {
// 	j = 0;
// 	while(j < 4)
// 	{
// 		printf("matrix[%d][%d] = %f \n", i, j, (*s->transformation_matrix)[i][j]);
// 		printf("m[%d][%d] = %f \n", i, j, (*m)[i][j]);
// 		j++;
// 	}
// 	i++;
// }
// t_intersections xs = intersect(s, r, gc);

// printf("xs.count = %d\n", xs.count);
// printf("xs[0] = %f\n", xs.xs[0].t);
// printf("xs[1] = %f\n", xs.xs[1].t);
// Scenario: Intersecting a translated sphere with a ray
// Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
// And s ← sphere()
// t_vector *v = vector (0, 0, 1, gc);
// t_vector *p = point(0, 0, -5, gc);
// t_ray *r = ray (p, v , gc); 
// // When set_transform(s, translation(5, 0, 0))
// set_transform(s, translation(point(5, 0, 0,gc),gc),gc);
// // And xs ← intersect(s, r)
// t_intersections xs = intersect(s, r, gc);
// printf("xs.count = %d\n", xs.count);
	return (0);
}
