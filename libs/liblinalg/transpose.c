/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:23:07 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 22:00:23 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*transpose(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	*matrix;

	matrix = (t_matrix *) malloc(sizeof(t_matrix));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j <= i)
		{
			*matrix[i][j] = m[j][i];
			*matrix[j][i] = m[i][j];
			j++;
		}
		i++;
	}
	return (matrix);
}
