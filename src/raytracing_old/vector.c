
#include "../../include/Minirt.h"

t_vector	*init_vector(double x, double y, double z, t_garbage_collector *gc)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		exit_function(gc, "error while init vector\n", 1, true);
	else
		add_pointer_node(gc, vector);
	vector->coordinate[0] = x;
	vector->coordinate[1] = y;
	vector->coordinate[2] = z;
	return (vector);
}

uint32_t	argb_to_hex(t_vector *color)
{
	int	g;
	int	r;
	int	b;
	int	a;

	a = 255;
	r = (int)(color->coordinate[0]);
	g = (int)(color->coordinate[1]);
	b = (int)(color->coordinate[2]);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}
