typedef struct s_camera {
	int			hsize;
	int			vsize;
	int			fov;
	int			pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	transformation_matrix;
}	t_camera;

typedef struct s_world {
	t_light		light;
	t_sphere	*spheres;
}	t_world;

// t_matrixt_computation

typedef double	color[3]	t_color;

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

// This is just 1 of 3 different shape types as an example
typedef struct s_sphere {
	// other sphere specific fields
	t_matrix	transformation_matrix;
	t_material	material;
}	t_sphere;

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
	int					count;
	t_intersection[100] xs;
}	t_intersections;

typedef	double vector[4] t_vector;

typedef	double vector[4][4] t_matrix;
