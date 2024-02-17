/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:01:26 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:07:57 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*vector(double a, double b, double c, t_garbage_collector *gc)
{
	t_vector	*vector;

	vector = (t_vector *) malloc(sizeof(t_vector));
	if (vector == NULL)
		exit_function(gc, "error allocating vector\n", 1, true);
	else
		add_pointer_node(gc, vector);
	vector->dim[0] = a;
	vector->dim[1] = b;
	vector->dim[2] = c;
	vector->dim[3] = 0;
	return (vector);
}
