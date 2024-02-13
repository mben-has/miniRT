/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:30:28 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 00:59:35 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*inverse(t_matrix *m, t_garbage_collector *gc)
{
	t_matrix	*inv;
	int			i;
	int			j;
	double		det;
	double		cofact;

	det = determinant_4x4(m, gc);
	if (det == 0)
		return (NULL);
	inv = (t_matrix *) malloc(sizeof(t_matrix));
	if (!inv)
		exit_function(gc, "error while allocate inv\n", 1, true);
	else
		add_pointer_node(gc, inv);
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			cofact = cofactor(m, i, j, gc);
			(*inv)[i][j] = cofact / det;
			i++;
		}
		j++;
	}
	return (inv);
}