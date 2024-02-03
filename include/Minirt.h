/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:40:38 by marschul          #+#    #+#             */
/*   Updated: 2024/02/03 22:25:10 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#define WIDTH 400
#define HEIGHT (int)(WIDTH/(16.9/9.0))
#define VP_HEIGHT 2.0
#define VP_WIDTH VP_HEIGHT * (double)(WIDTH/HEIGHT)

# include "libft.h"
# include "MLX42.h"
# include "../src/garbage_collector/garbage_collector.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_color {
	int	r;
	int	g;
	int b;
}	t_color;

typedef struct s_vector {
	double	coordinate[3];
}	t_vector;

typedef struct s_ambient {
	double	lighting_ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera {
	t_vector	*point;
	t_vector	*orientation;
	int			fov;
	double		distance;
}	t_camera;

typedef struct s_light {
	t_vector	point;
	double		brightness_ratio;
	t_color		color;
}	t_light;

typedef struct s_sphere {
	t_vector	point;
	double		diameter;
	t_color		color;
}	t_sphere;

typedef struct s_plane {
	t_vector	point;
	t_vector	normal_vector;
	t_color		color;
}	t_plane;

typedef struct s_cylinder {
	t_vector	point;
	t_vector	axis_vector;
	double		diameter;
	double		height;
	t_color		color;
}	t_cylinder;

typedef struct s_scene {
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
	int			nr_spheres;
	int			nr_planes;
	int			nr_cylinders;
}	t_scene;

typedef struct s_ray{
	t_vector* origin;
	t_vector* direction;
} t_ray;

typedef int (*t_function_pointer)(char **split, t_scene *scene);

// main
void	print_usage(void);

// parsing
int		parsing(char *file, t_scene *scene);
int		check_ambient(char **split, t_scene *scene);
int 	check_camera(char **split, t_scene *scene);
int 	check_light(char **split, t_scene *scene);
int 	check_sphere(char **split, t_scene *scene);
int 	check_plane(char **split, t_scene *scene);
int 	check_cylinder(char **split, t_scene *scene);
int		read_double(char *str, double *number, double range_left, double range_right);
int		word_length(char **split);
int		read_color(char *str, t_color *color);
int		read_byte(char *str, int range_left, int range_right);
int		read_vector(char *str, t_vector *vector, int is_normal);


// raytracing
int		raytracing(t_scene *scene, t_garbage_collector *gc);

//vector
t_vector		*init_vector(double x, double y, double z, t_garbage_collector *gc);
unsigned int	argb_to_hex(t_vector *color); //convert argb to hex

// get the height of image by ratio
int get_height(double ratio);

//camera
t_camera	*init_camera(t_vector *point, t_vector *orientation, int fov,t_garbage_collector *gc);
#endif