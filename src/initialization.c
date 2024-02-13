/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:57:00 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 21:23:59 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

t_vector	*vector_cast(t_vector_p *vector_parsing, t_garbage_collector *gc)
{
	t_vector	*v;

	v = vector(vector_parsing->coordinate[0], vector_parsing->coordinate[1], vector_parsing->coordinate[2], gc);
	return (v);
}

t_color	*color_cast(t_vector_p *vector_parsing, t_garbage_collector *gc)
{
	t_color	*col;

	col = color(vector_parsing->coordinate[0] / 255, vector_parsing->coordinate[1] / 255, vector_parsing->coordinate[2] / 255, gc);
	return (col);	
}

void	init_base(t_world *world)
{
	world->nr_objects = 0;
}

void	init_light(t_scene *scene, t_light *light, t_garbage_collector *gc)
{
	light->intensity = scene->light.brightness_ratio;
	light->position = vector_cast(scene->light.point, gc);
}

t_matrix	*get_matrix_sphere(t_sphere_p *sphere_parsing, t_garbage_collector *gc)
{
	t_matrix	*m1;
	t_matrix	*m2;
	t_matrix	*m3;
	t_vector	*v;
	double		radius;

	v = vector_cast(sphere_parsing->point, gc);
	m1 = translation(v, gc);
	radius = sphere_parsing->diameter / 2;
	v = vector(radius, radius, radius, gc);
	m2 = scaling(v, gc);
	m3 = matrix_mult_m(m1, m2, gc);
	return (m3);
}

void	fill_data_sphere(t_sphere *sphere, t_sphere_p *sphere_parsing, t_ambient ambient, t_garbage_collector *gc)
{
	sphere->material.color = color_cast(sphere_parsing->color, gc);
	sphere->material.ambient = ambient.lighting_ratio;
	sphere->material.diffuse = DIFFUSE;
	sphere->material.specular = SPECULAR;
	sphere->material.shininess = SHININESS;
	sphere->transformation_matrix = get_matrix_sphere(sphere_parsing, gc);
}

void	add_spheres(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int			i;
	t_object	*obj;
	t_sphere	*sphere;

	i = 0;
	while (i < scene->nr_spheres)
	{
		obj = &world->objects[world->nr_objects];
		obj->id = 's';
		sphere = (t_sphere *) malloc(sizeof(t_sphere));
		if (sphere == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, sphere);
		sphere->transformation_matrix = identity_matrix(gc);
		obj->sphere = sphere;
		obj->plane = NULL;
		obj->cylinder = NULL;
		world->nr_objects++;
		fill_data_sphere(sphere, scene->spheres[i], scene->ambient, gc);
		i++;
	}
}

void	add_planes(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int			i;
	t_object	*obj;
	t_plane		*plane;

	i = 0;
	while (i < scene->nr_planes)
	{
		obj = &world->objects[world->nr_objects];
		obj->id = 'p';
		plane = (t_plane *) malloc(sizeof(t_plane));
		if (plane == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, plane);
		obj->plane = plane;
		obj->sphere = NULL;
		obj->cylinder = NULL;
		world->nr_objects++;
		i++;
	}
}

void	add_cylinders(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int			i;
	t_object	*obj;
	t_cylinder	*cylinder;

	i = 0;
	while (i < scene->nr_cylinders)
	{
		obj = &world->objects[world->nr_objects];
		obj->id = 'c';
		cylinder = (t_cylinder *) malloc(sizeof(t_cylinder));
		if (cylinder == NULL)
			exit_function(gc, "malloc failed\n", 1, 1);
		else
			add_pointer_node(gc, cylinder);
		obj->cylinder = cylinder;
		obj->plane = NULL;
		obj->sphere = NULL;
		world->nr_objects++;
		i++;
	}
}

void	init_objects(t_scene *scene, t_world *world, t_garbage_collector *gc)
{
	int	nr_objects;

	nr_objects = scene->nr_spheres + scene->nr_planes + scene->nr_cylinders;
	world->objects = (t_object *) malloc (nr_objects * sizeof(t_object));
	if (world->objects == NULL)
		exit_function(gc, "malloc failed\n", 1, 1);
	else
		add_pointer_node(gc, world->objects);
	add_spheres(scene, world, gc);
	add_planes(scene, world, gc);
	add_cylinders(scene, world, gc);
}

void	init_camera(t_scene *scene ,t_camera *cam, t_garbage_collector *gc)
{
	double		half_diag; //lenght diagonal across virtual screen * 0.5
	double		fov_radians;
	t_vector	*aux;
	
	(*cam).point = point(scene->camera.point->coordinate[0], scene->camera.point->coordinate[1], scene->camera.point->coordinate[2], gc);
	(*cam).orientation = vector(scene->camera.orientation->coordinate[0], scene->camera.orientation->coordinate[1], scene->camera.orientation->coordinate[2], gc);
	(*cam).fov = scene->camera.fov;
	fov_radians = (*cam).fov * (M_PI / 180.0);
	half_diag = sqrt(((HEIGHT * 0.5) * (HEIGHT * 0.5)) + ((WIDTH * 0.5) * (WIDTH
					* 0.5)));
	(*cam).focal_length = half_diag / tan(fov_radians / 2.0);

 if ((*cam).orientation->dim[0] == 0.0f
        && ((*cam).orientation->dim[1] == 1.0f || (*cam).orientation->dim[1] == -1.0f)
        && (*cam).orientation->dim[2] == 0.0f)
        {
			aux = vector(0 , 0.0, -1.0,gc);
		}
		else
		{
			aux = vector(0.0, 1.0, 0.0,gc);
		}
	
	(*cam).v_width= normalize(cross(aux, (*cam).orientation,  gc), gc); 
	(*cam).v_width = scalar_mult((*cam).v_width  , WIDTH * 0.5, gc);
	(*cam).v_height = normalize(cross((*cam).orientation, (*cam).v_width, gc), gc);
	(*cam).v_height  = scalar_mult((*cam).v_height   , HEIGHT * 0.5, gc);
	(*cam).v_cam_canvas = scalar_mult((*cam).orientation, (*cam).focal_length, gc);
	(*cam).v_cam_canvas = vector_add((*cam).v_cam_canvas, (*cam).point, gc);
	aux = vector_subtract((*cam).v_height, (*cam).v_width, gc);
	(*cam).pixel00 = vector_add((*cam).v_cam_canvas,aux, gc);
	(*cam).v_width= normalize((*cam).v_width, gc);
	(*cam).v_height= normalize((*cam).v_height, gc);
	printf("fov = %d\n", (*cam).fov);
	printf("focal length = %f\n", (*cam).focal_length);
	printf("lenght half_diag = %f\n", half_diag);
	printf("pixel00 (%f, %f, %f, %f)\n", (*cam).pixel00->dim[0], (*cam).pixel00->dim[1], (*cam).pixel00->dim[2], (*cam).pixel00->dim[3]);
	printf("cam_coordinations = (%f, %f, %f, %f)\n", (*cam).point->dim[0], (*cam).point->dim[1],(*cam).point->dim[2], (*cam).point->dim[3]);
	printf("cam_orientation = (%f, %f, %f, %f)\n", (*cam).orientation->dim[0], (*cam).orientation->dim[1],(*cam).orientation->dim[2], (*cam).orientation->dim[3]);
	// printf("v-height_coordinations = (%f, %f, %f, %f)\n", (*cam).v_height->dim[0], (*cam).v_height->dim[1],(*cam).v_height->dim[2], (*cam).v_height->dim[3]);
	// printf("v-width_coordinations = (%f, %f, %f, %f)\n", (*cam).v_width->dim[0], (*cam).v_width->dim[1],(*cam).v_width->dim[2], (*cam).v_width->dim[3]);
}

/*
Initializes world and camera with the data in scene.
*/
void	init_world(t_scene *scene, t_world *world, t_camera *camera, t_garbage_collector *gc)
{
	init_base(world);
	init_light(scene, &world->light, gc);
	init_objects(scene, world, gc);
	init_camera(scene, camera, gc);
}
