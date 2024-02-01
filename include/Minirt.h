/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:40:38 by marschul          #+#    #+#             */
/*   Updated: 2024/02/01 13:09:35 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_ambient {
	char	type;
}	t_ambient;

typedef struct s_camera {
	char	type;
}	t_camera;

typedef struct s_light {
	char	type;
}	t_light;

typedef struct s_sphere {
	char	type;
}	t_sphere;

typedef struct s_plane {
	char	type;
}	t_plane;

typedef struct s_cylinder {
	char	type;
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

void	print_usage(void);
int		parsing(char *file, t_scene *scene);
int		raytracing(t_scene *scene);

#endif
