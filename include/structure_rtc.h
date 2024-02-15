/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_rtc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:34:24 by marschul          #+#    #+#             */
/*   Updated: 2024/02/15 07:31:37 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_RTC_H
# define STRUCTURE_RTC_H

# ifndef LIBLINALG_H

	typedef	double t_vector[4];

	typedef	double t_matrix[4][4];

	typedef double t_color[3];
	
# endif

# define DIFFUSE	0.9
# define SPECULAR	0.9
# define SHININESS	200.0

typedef struct s_camera {
	int			hsize;
	int			vsize;
	int			fov;
	int			pixel_size;
	double		half_width;
	double		half_height;
	double		focal_length; // distance between camera and the virtual screen
	t_vector	*v_cam_canvas; // vector from camera to the virtual screen
	t_vector	*orientation; //orientation of the camera
	t_vector	*v_width;// normalized vector across width
	t_vector	*v_height;// normalized vector across heigth
	t_vector	*point;//center of the camera
	t_vector	*pixel00;//upper_left_point
	t_matrix	transformation_matrix;
}	t_camera;

typedef struct s_material {
	t_color		*color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

typedef struct s_computation {
	t_material	*material;
	t_vector	*point;
	t_vector	*lightv;
	t_vector	*normalv;
	t_vector	*eyev;
	t_vector	*reflectv;
	t_color		*effective_color;
	t_color		*light_color;
	double		dot_light_normal;
	double		dot_reflect_eye;
	t_vector	*over_point;
}	t_computation;

typedef	struct s_light {
	t_vector	*position;
	double		intensity;
}	t_light;

typedef	struct s_ray {
	t_vector	*origin;
	t_vector	*direction;
}	t_ray;

typedef struct s_sphere {
	// other specific fields
	t_matrix	*transformation_matrix;
	t_material	material;
}	t_sphere;

typedef struct s_plane {
	// other specific fields
	t_matrix	*transformation_matrix;
	t_material	material;
}	t_plane;

typedef struct s_cylinder {
	// other specific fields
	t_matrix	*transformation_matrix;
	t_material	material;
}	t_cylinder;

typedef struct s_object 
{
	char		id;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_object;

typedef struct s_intersection {
	double		t;
	t_object	*object;
}	t_intersection;

typedef struct s_intersections {
	int				count;
	t_intersection	xs[100];
}	t_intersections;

typedef struct s_world {
	t_light		light;
	t_object	*objects;
	int			nr_objects;
}	t_world;

//light.c
t_color	*color_at(t_world *world, t_ray *ray, t_garbage_collector *gc, int i, int j);

//ray
t_ray *ray(t_vector *origin, t_vector *direction, t_garbage_collector *gc);
t_vector *position(t_ray *ray, double t, t_garbage_collector *gc);
t_intersections intersect(t_object o, t_ray *r, t_garbage_collector *gc);
t_intersections intersect_sphere(t_sphere *s, t_ray *r, t_garbage_collector *gc);
t_intersections intersect_plane(t_object object, t_ray *r, t_garbage_collector *gc);
t_intersection intersection(double t, t_sphere *s, t_garbage_collector *gc);
t_intersections intersections(t_intersection first, ...);//last parameter should be NULL
t_intersection hit(t_intersections xs, double focal_length);
t_intersections intersect_world(t_world *world, t_ray *r, t_garbage_collector *gc);
t_ray *transform(t_ray *r, t_matrix *m, t_garbage_collector *gc);
void set_transform(t_sphere *s, t_matrix *m, t_garbage_collector *gc);
void print_matrix(t_matrix *m);

#endif 