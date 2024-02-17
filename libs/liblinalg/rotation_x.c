/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:20:39 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:09:55 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*rotation_x(double radians, t_garbage_collector *gc)
{
	t_matrix	*m;

	m = identity_matrix(gc);
	if (m == NULL)
		return (NULL);
	(*m)[1][1] = cos(radians);
	(*m)[2][2] = cos(radians);
	(*m)[1][2] = -sin(radians);
	(*m)[2][1] = sin(radians);
	return (m);
}
