/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:49:41 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:10:46 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*matrix_mult_v(t_matrix *m, t_vector *v, t_garbage_collector *gc)
{
	t_vector	*result;
	int			j;
	double		column[4];

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		exit_function(gc, "error allocating mult_v\n", 1, true);
	else
		add_pointer_node(gc, result);
	column[0] = v->dim[0];
	column[1] = v->dim[1];
	column[2] = v->dim[2];
	column[3] = v->dim[3];
	j = 0;
	while (j < 4)
	{
		result->dim[j] = row_by_column((*m)[j], column);
		j++;
	}
	return (result);
}
