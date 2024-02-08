/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:23:51 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 19:51:22 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*rotation_y(double radians)
{
	t_matrix	*m;

	m = identity_matrix();
	if (m == NULL)
		return (NULL);
	(*m)[0][0] = cos(radians);
	(*m)[2][2] = cos(radians);
	(*m)[0][2] = sin(radians);
	(*m)[2][0] = -sin(radians);
	return(m);
}
