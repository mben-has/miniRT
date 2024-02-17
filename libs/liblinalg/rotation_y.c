/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:23:51 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:09:46 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*rotation_y(double radians, t_garbage_collector *gc)
{
	t_matrix	*m;

	m = identity_matrix(gc);
	if (m == NULL)
		return (NULL);
	(*m)[0][0] = cos(radians);
	(*m)[2][2] = cos(radians);
	(*m)[0][2] = sin(radians);
	(*m)[2][0] = -sin(radians);
	return (m);
}
