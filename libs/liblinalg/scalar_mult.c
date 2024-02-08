/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:55:56 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 19:43:17 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*scalar_mult(t_vector *a, double c)
{
	t_vector	*result;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	result->dim[0] = c * a->dim[0];
	result->dim[1] = c * a->dim[1];
	result->dim[2] = c * a->dim[2];
	result->dim[3] = 0.0;
	return (result);
}
