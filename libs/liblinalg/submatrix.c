/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:31:17 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 00:54:20 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

static void	copy(t_matrix *sub, t_matrix *m)
{
	int	i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			(*sub)[j][i] = (*m)[j][i];
			i++;
		}
		j++;
	}
}

t_matrix	*submatrix(t_matrix *m, int x, int y, t_garbage_collector *gc)
{
	t_matrix	*sub;
	int 		i;
	int 		j;

	sub = (t_matrix*) malloc(sizeof(t_matrix));
	if (sub == NULL)
		exit_function(gc, "error malloc submatrix \n", 1, true);
	else
		add_pointer_node(gc, sub);
	copy(sub, m);
	j = y + 1;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			(*sub)[j - 1][i] = (*m)[j][i];
			i++;
		}
		j++;
	}
	j = 0;
	while (j < 4)
	{
		i = x + 1;
		while (i < 4)
		{
			(*sub)[j][i - 1] = (*sub)[j][i];
			i++;
		}
		j++;
	}
	return (sub);
}
