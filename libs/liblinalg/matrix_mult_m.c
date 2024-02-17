/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:09:13 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:28:10 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

void	fill_column(t_matrix *b, int i, double *column)
{
	column[0] = (*b)[0][i];
	column[1] = (*b)[1][i];
	column[2] = (*b)[2][i];
	column[3] = (*b)[3][i];
}

t_matrix	*matrix_mult_m(t_matrix *a, t_matrix *b, t_garbage_collector *gc)
{
	int			i;
	int			j;
	double		column[4];
	t_matrix	*result;

	result = (t_matrix *) malloc(sizeof(t_matrix));
	if (result == NULL)
		exit_function(gc, "error allocating matrix\n", 1, true);
	else
		add_pointer_node(gc, result);
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			fill_column(b, i, column);
			(*result)[j][i] = row_by_column((*a)[j], column);
			i++;
		}
		j++;
	}
	return (result);
}
