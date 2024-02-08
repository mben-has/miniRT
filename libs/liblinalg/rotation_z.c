/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:25:06 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 19:51:44 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*rotation_z(double radians)
{
	t_matrix	*m;

	m = identity_matrix();
	if (m == NULL)
		return (NULL);
	(*m)[0][0] = cos(radians);
	(*m)[1][1] = cos(radians);
	(*m)[0][1] = -sin(radians);
	(*m)[1][0] = sin(radians);
	return(m);
}
