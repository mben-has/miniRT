/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:49:15 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 20:57:39 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*identity_matrix()
{
	t_matrix	*m;
	int			i;
	int			j;

	m = (t_matrix *) malloc(sizeof(t_matrix));
	if (m == NULL)
		return (NULL);
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (i == j)
				*m[j][i] = 1.0;
			else
				*m[j][i] = 0.0;
			i++;
		}
		j++;
	}
	return (m);
}
