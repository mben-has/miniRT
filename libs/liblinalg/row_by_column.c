/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_by_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:59:34 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 18:08:57 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

double	row_by_column(double row[4], double column[4])
{
	double	result;
	int		i;

	result = 0;
	i = 0;
	while (i < 4)
	{
		result += row[i] * column[i];
		i++;
	}
	return (result);
}
