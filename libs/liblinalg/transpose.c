/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:23:07 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:08:11 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*transpose(t_matrix *m, t_garbage_collector *gc)
{
	int			i;
	int			j;
	t_matrix	*matrix;

	matrix = (t_matrix *) malloc(sizeof(t_matrix));
	if (matrix == NULL)
		exit_function(gc, "error allocating matrix\n", 1, true);
	else
		add_pointer_node(gc, matrix);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j <= i)
		{
			(*matrix)[i][j] = (*m)[j][i];
			(*matrix)[j][i] = (*m)[i][j];
			j++;
		}
		i++;
	}
	return (matrix);
}
