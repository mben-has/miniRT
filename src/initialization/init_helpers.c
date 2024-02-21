/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:29:47 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/20 23:36:09 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"

t_vector	*vector_cast(t_vector_p *vector_parsing, t_garbage_collector *gc)
{
	t_vector	*v;

	v = vector(vector_parsing->coordinate[0], vector_parsing->coordinate[1],
			vector_parsing->coordinate[2], gc);
	return (v);
}

t_color	*color_cast(t_vector_p *vector_parsing, t_garbage_collector *gc)
{
	t_color	*col;

	col = color(vector_parsing->coordinate[0] / 255, \
		vector_parsing->coordinate[1] / 255, \
		vector_parsing->coordinate[2] / 255, gc);
	return (col);
}

int	is_vector_normal(t_vector_p *vector, t_garbage_collector *gc)
{
	t_vector	*v;

	v = vector_cast(vector, gc);
	if (double_equal(magnitude(v), 1.0))
		return (1);
	else
		return (0);
}

void	get_angles(t_vector *vec, double *x, double *z)
{
	double	ratio;

	ratio = sqrt((vec->dim[0] * vec->dim[0]) + (vec->dim[1] * vec->dim[1]));
	if (ratio == 0.0)
		*z = M_PI * 0.5;
	else
		*z = acos(vec->dim[1] / ratio);
	*x = acos(ratio);
}

t_matrix	*get_rotation_matrix(t_vector *v_normal, t_garbage_collector *gc)
{
	t_matrix	*rotation_matrix;
	t_matrix	*rx;
	t_matrix	*rz;
	double		x_angle;
	double		z_angle;

	get_angles(v_normal, &x_angle, &z_angle);
	rz = rotation_z(z_angle, gc);
	rx = rotation_x(x_angle, gc);
	rotation_matrix = matrix_mult_m(rz, rx, gc);
	return (rotation_matrix);
}
