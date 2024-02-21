/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_rtc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:34:24 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 17:28:36 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_RTC_H
# define STRUCTURE_RTC_H

# include <stdarg.h>

# ifndef LIBLINALG_H

typedef double	t_vector[4];
typedef double	t_matrix[4][4];
typedef double	t_color[3];

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
	double		focal_length;
	double		width;
	double		height;
	t_vector	*v_cam_canvas;
	t_vector	*orientation;
	t_vector	*v_width;
	t_vector	*v_height;
	t_vector	*point;
	t_vector	*pixel00;
	t_matrix	transformation_matrix;
}	t_camera;

typedef struct s_material {
	t_color		*color;
	t_color		*ambient;
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

typedef struct s_light {
	t_vector	*position;
	double		intensity;
}	t_light;

typedef struct s_ray {
	t_vector	*origin;
	t_vector	*direction;
	double		original_length;
}	t_ray;

typedef struct s_sphere {
	t_matrix	*transformation_matrix;
	t_material	material;
}	t_sphere;

typedef struct s_plane {
	t_matrix	*transformation_matrix;
	t_material	material;
}	t_plane;

typedef struct s_cylinder {
	t_matrix	*transformation_matrix;
	t_material	material;
	double		minimum;
	double		maximum;
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

//light functions
t_color			*color_at(t_world *world, t_ray *ray, t_garbage_collector *gc);
t_color			*get_black(t_garbage_collector *gc);
void			prepare_computations_1(t_computation *comp, t_intersection \
	*intersection, t_ray *ray, t_garbage_collector *gc);
void			prepare_computations_2(t_computation *comp, t_light light, \
	t_garbage_collector *gc);
bool			is_shadowed(t_world *world, t_vector *p, \
	t_garbage_collector *gc);
t_color			*lighting(t_computation *computation, bool shadowed, \
	t_garbage_collector *gc);
t_matrix		*get_transformation_matrix(t_object *object);
t_material		*get_material(t_object *object);
t_vector		*compute_point(t_ray *ray, t_intersection *intersection, \
	t_garbage_collector *gc);
t_vector		*normal_at(t_object *object, t_matrix *transformation_matrix, \
	t_vector *p, t_garbage_collector *gc);
t_vector		*reflect(t_vector *in, t_vector *normal, \
	t_garbage_collector *gc);
t_vector		*compute_over_point(t_vector *p, t_vector *normalv, \
	t_garbage_collector *gc);
t_color			*get_ambient(t_color *ambient, t_computation *computation, \
	t_garbage_collector *gc);
t_color			*get_diffuse(double diffuse, t_computation *computation, \
	t_garbage_collector *gc);
t_color			*get_specular(double specular, t_computation *computation, \
	t_garbage_collector *gc);
t_vector		*get_cylinder_normal(t_object *object, t_vector *p, \
	t_garbage_collector *gc);

//ray.c
t_ray			*ray(t_vector *origin, t_vector *direction, \
	t_garbage_collector *gc);
t_vector		*position(t_ray *ray, double t, t_garbage_collector *gc);
t_intersections	intersect(t_object o, t_ray *r, t_garbage_collector *gc);
t_intersections	intersect_plane(t_object object, t_ray *r, \
	t_garbage_collector *gc);
t_intersections	intersect_sphere(t_object o, t_ray *r, \
	t_garbage_collector *gc);
t_intersection	intersection(double t, t_object object, \
	t_garbage_collector *gc);
t_intersections	intersections(t_intersection first, ...);
t_intersection	hit(t_intersections xs, double focal_length);
t_intersections	intersect_world(t_world *world, t_ray *r, \
	t_garbage_collector *gc);
t_ray			*transform(t_ray *r, t_matrix *m, t_garbage_collector *gc);
void			set_transform(t_sphere *s, t_matrix *m, \
	t_garbage_collector *gc);
void			print_matrix(t_matrix *m);
void			sort_intersections(t_intersections *xs);
t_intersections	intersect_cylinder(t_object o, t_ray *r, \
	t_garbage_collector *gc);
t_ray			*ray_with_orignal_length(t_ray *r, t_garbage_collector *gc);
double			length_vector(t_vector *v, t_vector *point, \
	t_garbage_collector *gc);
t_intersection	intersection_sphere(double t, t_object *object, \
	t_garbage_collector *gc);
t_intersection	intersection_plane(double t, t_object *object, \
	t_garbage_collector *gc);
t_intersection	intersection_cylinder(double t, t_object *object, \
	t_garbage_collector *gc);

#endif 