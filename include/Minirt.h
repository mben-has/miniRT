/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:40:38 by marschul          #+#    #+#             */
/*   Updated: 2024/02/21 17:34:42 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <assert.h>
# include "libft.h"
# include "liblinalg.h"
# include "MLX42.h"
# include "garbage_collector.h"
# include "structure_rtc.h"

typedef struct s_vector_p {
	double	coordinate[3];
}	t_vector_p;

typedef struct s_ambient {
	double		lighting_ratio;
	t_vector_p	*color;
}	t_ambient;

typedef struct s_camera_p {
	t_vector_p	*point;
	t_vector_p	*orientation;
	t_vector_p	*o_vp;
	t_vector_p	*radius;
	int			fov;
	double		distance;
}	t_camera_p;

typedef struct s_light_p {
	t_vector_p	*point;
	double		brightness_ratio;
	t_vector_p	*color;
}	t_light_p;

typedef struct s_sphere_p {
	char		id;
	t_vector_p	*point;
	double		diameter;
	double		radius;
	t_vector_p	*color;
}	t_sphere_p;

typedef struct s_plane_p {
	char		id;
	t_vector_p	*point;
	t_vector_p	*normal_vector;
	t_vector_p	*color;
}	t_plane_p;

typedef struct s_cylinder_p {
	char		id;
	t_vector_p	*point;
	t_vector_p	*axis_vector;
	double		diameter;
	double		height;
	t_vector_p	*color;
}	t_cylinder_p;

typedef struct s_scene {
	t_ambient		ambient;
	t_camera_p		camera;
	t_light_p		light;
	t_sphere_p		**spheres;
	t_plane_p		**planes;
	t_cylinder_p	**cylinders;
	int				nr_spheres;
	int				nr_planes;
	int				nr_cylinders;
}	t_scene;

typedef bool	(*t_function_pointer)(char **split, t_scene *scene, \
	t_garbage_collector *gc);

// helper_fumctions
void			print_usage(void);

// parsing directory
void			parsing(char *file, t_scene *scene, t_garbage_collector *gc);
bool			check_file_extension(char *file);
bool			check_for_unique(int i);
bool			check_ambient(char **split, t_scene *scene, \
	t_garbage_collector *gc);
bool			check_camera(char **split, t_scene *scene, \
	t_garbage_collector *gc);
bool			check_light(char **split, t_scene *scene, \
	t_garbage_collector *gc);
bool			check_sphere(char **split, t_scene *scene, \
	t_garbage_collector *gc);
bool			check_plane(char **split, t_scene *scene, \
	t_garbage_collector *gc);
bool			check_cylinder(char **split, t_scene *scene, \
	t_garbage_collector *gc);
bool			read_double(char *str, double *number, double range_left, \
	double range_right);
int				word_length(char **split);
bool			read_color(char *str, t_vector_p **color, \
	t_garbage_collector *gc);
int				read_byte(char *str, int range_left, int range_right);
bool			read_vector(char *str, t_vector_p **vector, int is_normal, \
	t_garbage_collector *gc);
int				word_length(char **split);
int				read_byte(char *str, int range_left, int range_right);
bool			read_color(char *str, t_vector_p **color, \
	t_garbage_collector *gc);

// initialization
void			init_world(t_scene *scene, t_world *world, t_camera *camera, \
	t_garbage_collector *gc);
t_vector		*vector_cast(t_vector_p *vector_parsing, \
	t_garbage_collector *gc);
t_color			*color_cast(t_vector_p *vector_parsing, \
	t_garbage_collector *gc);
int				is_vector_normal(t_vector_p *vector, t_garbage_collector *gc);
void			init_base(t_world *world);
void			init_light(t_scene *scene, t_light *light, \
	t_garbage_collector *gc);
t_matrix		*set_matrix_sphere(t_sphere_p *sphere_parsing, \
	t_garbage_collector *gc);
void			fill_data_sphere(t_sphere *sphere, t_sphere_p *sphere_parsing, \
	t_ambient ambient, t_garbage_collector *gc);
void			add_spheres(t_scene *scene, t_world *world, \
	t_garbage_collector *gc);
void			get_angles(t_vector *vec, double *x, double *z);
t_matrix		*set_matrix_plane(t_plane_p *plane_parsing, \
	t_garbage_collector *gc);
void			fill_data_plane(t_scene *scene, t_plane *plane, \
	t_plane_p *plane_parsing, t_garbage_collector *gc);
void			add_planes(t_scene *scene, t_world *world, \
	t_garbage_collector *gc);
t_matrix		*set_matrix_cylinder(t_cylinder_p *cp, t_garbage_collector *gc);
void			fill_data_cylinder(t_cylinder *cylinder, t_cylinder_p \
	*cylinder_parsing, t_ambient ambient, t_garbage_collector *gc);
void			add_cylinders(t_scene *scene, t_world *world, \
	t_garbage_collector *gc);
void			init_objects(t_scene *scene, t_world *world, \
	t_garbage_collector *gc);
void			init_camera(t_scene *scene, t_camera *cam, \
	t_garbage_collector *gc);
t_matrix		*get_rotation_matrix(t_vector *v_normal, \
	t_garbage_collector *gc);
// raytracing directory
int				raytracing(t_world *world, t_camera *camera, \
	t_garbage_collector *gc);
unsigned int	rgb_to_hex(t_color *col);
t_computation	*prepare_computations(t_intersection *intersection, t_ray *ray, \
	t_light light, t_garbage_collector *gc);
double			length_vector(t_vector *v, t_vector *point, \
	t_garbage_collector *gc);
void			print_matrix(t_matrix *m);

#endif