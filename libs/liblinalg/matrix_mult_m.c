/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:09:13 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 12:05:29 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"
#include <stdio.h>
t_matrix	*matrix_mult_m(t_matrix *a, t_matrix *b)
{
	int			i;
	int			j;
	double		column[4];
	t_matrix	*result;

	result = (t_matrix *) malloc(sizeof(t_matrix));
	if (result == NULL)
		return (NULL);a++;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			column[0] = *(b[0])[i]; 
			column[1] = *(b[1])[i]; 
			column[2] = *(b[2])[i]; 
			column[3] = *(b[3])[i]; 
			// *result[j][i] = row_by_column((double/ *) *(a[j]), column);
			*result[j][i] = 1.0;
			printf("+ %f\n", *(b[j])[i]);
			i++;
		}
		j++;
	}
	return (result);
}
