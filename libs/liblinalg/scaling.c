/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:17:57 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 22:11:17 by mben-has         ###   ########.fr       */
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
	return(m);
}
