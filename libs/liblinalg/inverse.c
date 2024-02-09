/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:30:28 by marschul          #+#    #+#             */
/*   Updated: 2024/02/09 15:44:21 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*inverse(t_matrix *m)
{
	t_matrix	*inv;
	int			i;
	int			j;
	double		det;
	double		cofact;

	det = determinant_4x4(m);
	if (det == 0)
		return (NULL);
	inv = (t_matrix *) malloc(sizeof(t_matrix));
	if (inv == NULL)
		return (NULL);
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			cofact = cofactor(m, i, j);
			(*inv)[i][j] = cofact / det;
			i++;
		}
		j++;
	}
	return (inv);
}