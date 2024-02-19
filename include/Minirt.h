/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:40:38 by marschul          #+#    #+#             */
/*   Updated: 2024/02/19 15:49:53 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800
# define HEIGHT (int)(WIDTH/(16.9/9.0))
# define VP_HEIGHT 2.0
# define VP_WIDTH VP_HEIGHT * (double)(WIDTH/HEIGHT)

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

typedef int	(*t_function_pointer)(char **split, t_scene *scene, \
	t_garbage_collector *gc);

// main
void			print_usage(void);

// parsing
void			parsing(char *file, t_scene *scene, t_garbage_collector *gc);
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

// initialization
void			init_world(t_scene *scene, t_world *world, t_camera *camera, \
	t_garbage_collector *gc);

// raytracing
int				raytracing(t_world *world, t_camera *camera, \
	t_garbage_collector *gc);
unsigned int	rgb_to_hex(t_color *col);

//computation
t_computation	*prepare_computations(t_intersection *intersection, t_ray *ray, \
	t_light light, t_garbage_collector *gc);

//normal vector check
int				is_vector_normal(t_vector_p *vector);

#endif