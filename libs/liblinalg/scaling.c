/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:57 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:09:23 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_matrix	*scaling(t_vector *point, t_garbage_collector *gc)
{
	t_matrix	*m;

	m = identity_matrix(gc);
	if (m == NULL)
		return (NULL);
	(*m)[0][0] = point->dim[0];
	(*m)[1][1] = point->dim[1];
	(*m)[2][2] = point->dim[2];
	return (m);
}
