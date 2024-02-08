/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.mag                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:39:42 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 17:41:58 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*normalize(t_vector *vector)
{
	t_vector	*result;
	double		mag;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	mag = magnitude(vector);
	result->dim[0] = vector->dim[0] / mag;
	result->dim[1] = vector->dim[1] / mag;
	result->dim[2] = vector->dim[2] / mag;
	result->dim[3] = vector->dim[3] / mag;
	return (result);
}