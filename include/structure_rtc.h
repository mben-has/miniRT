/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_rtc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:34:24 by marschul          #+#    #+#             */
/*   Updated: 2024/02/06 18:56:40 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_RTC_H
# define STRUCTURE_RTC_H

typedef	double t_vector[4];

typedef	double t_matrix[4][4];

typedef double t_color[3];

typedef struct s_camera {
	int			hsize;
	int			vsize;
	int			fov;
	int			pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	transformation_matrix;
}	t_camera;

// t_computation

typedef struct s_material {
	t_color		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

typedef	struct s_light {
	t_vector	position;
	double		intensity;
}	t_light;

typedef	struct s_ray {
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_sphere {
	// other specific fields
	t_matrix	transformation_matrix;
	t_material	material;
}	t_sphere;

typedef struct s_plane {
	// other specific fields
	t_matrix	transformation_matrix;
	t_material	material;
}	t_plane;

typedef struct s_cylinder {
	// other specific fields
	t_matrix	transformation_matrix;
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
	t_object	object;
}	t_intersection;

typedef struct s_intersections {
	int				count;
	t_intersection	xs[100];
}	t_intersections;

typedef struct s_world {
	t_light		light;
	t_sphere	*spheres;
}	t_world;

#endif 