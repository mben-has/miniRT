typedef struct s_camera {
	int	hsize;
	int	vsize;
	int	fov;
	t_matrix	transformation_matrix;
}	t_camera;

typedef struct s_world {
	t_light		light;
	t_sphere	*spheres;
}	t_world;

t_computation

typedef struct s_material {
	t_vector	color;
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
	t_matrix	transformation_matrix;
	t_material	material;
}	t_sphere;

typedef struct s_intersection {
	double		t;
	t_sphere	sphere;
};

t_intersection

typedef struct s_intersections {
	int					count;
	t_intersection[100] xs;
}	t_intersections;

typedef	double vector[4] t_vector;

typedef	double vector[4][4] t_matrix;
