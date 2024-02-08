/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:01:47 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 20:01:06 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*cross(t_vector *a, t_vector *b)
{
	t_vector	*result;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	result->dim[0] = a->dim[1] * b->dim[2] - a->dim[2] * b->dim[1];
	result->dim[1] = a->dim[2] * b->dim[0] - a->dim[0] * b->dim[2];
	result->dim[2] = a->dim[0] * b->dim[1] - a->dim[1] * b->dim[0];
	result->dim[3] = 0.0;
	return (result);
}
