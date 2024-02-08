/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:01:24 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 19:45:36 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*scalar_div(t_vector *a, double c)
{
	t_vector	*result;

	result = (t_vector *) malloc(sizeof(t_vector));
	if (result == NULL)
		return (NULL);
	result->dim[0] = a->dim[0] / c;
	result->dim[1] = a->dim[1] / c;
	result->dim[2] = a->dim[2] / c;
	result->dim[3] = 0.0;
	return (result);
}
