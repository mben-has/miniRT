/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:49:27 by marschul          #+#    #+#             */
/*   Updated: 2024/02/09 13:52:19 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

double	cofactor(t_matrix *m, int i, int j)
{
	int	neg;

	if ((i + j) % 2 == 0)
		neg = 1;
	else
		neg = -1;
	return (neg * minor(m, i, j));
}
