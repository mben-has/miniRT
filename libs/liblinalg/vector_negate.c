/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_negate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:49:52 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 22:21:42 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*vector_negate(t_vector *a, t_garbage_collector *gc)
{
	t_vector	*result;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		exit_function(gc, "error allocating vector\n", 1, true);
	else
		add_pointer_node(gc, result);
	result->dim[0] = -a->dim[0];
	result->dim[1] = -a->dim[1];
	result->dim[2] = -a->dim[2];
	result->dim[3] = 0.0;
	return (result);
}
