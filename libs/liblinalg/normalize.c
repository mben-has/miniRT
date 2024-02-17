/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:39:42 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:10:24 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*normalize(t_vector *vector, t_garbage_collector *gc)
{
	t_vector	*result;
	double		mag;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		exit_function(gc, "error allocating norm_vector\n", 1, true);
	else
		add_pointer_node(gc, result);
	mag = magnitude(vector);
	result->dim[0] = vector->dim[0] / mag;
	result->dim[1] = vector->dim[1] / mag;
	result->dim[2] = vector->dim[2] / mag;
	result->dim[3] = vector->dim[3];
	return (result);
}
