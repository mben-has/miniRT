/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:55:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 20:29:26 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*scalar_mult(t_vector *a, double c, t_garbage_collector *gc)
{
	t_vector	*result;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		exit_function(gc, "error allocating vector\n", 1, true);
	else
		add_pointer_node(gc, result);
	result->dim[0] = c * a->dim[0];
	result->dim[1] = c * a->dim[1];
	result->dim[2] = c * a->dim[2];
	result->dim[3] = a->dim[3];
	return (result);
}
