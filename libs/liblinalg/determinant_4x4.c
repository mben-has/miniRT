/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant_4x4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:31:03 by marschul          #+#    #+#             */
/*   Updated: 2024/02/09 16:12:30 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

double	determinant_4x4(t_matrix *m)
{
	double	det;
	int		i;

	det = 0;
	i = 0;
	while (i < 4)
	{
		det += (*m)[0][i] * cofactor(m, i, 0);
		i++;
	}
	return (det);
}
