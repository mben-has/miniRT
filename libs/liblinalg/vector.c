/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:01:26 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 20:04:54 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*vector(double a, double b, double c)
{
	t_vector	*vector;

	vector = (t_vector *) malloc(sizeof(t_vector));
	if (vector == NULL)
		return (NULL);
	vector->dim[0] = a;
	vector->dim[1] = b;
	vector->dim[2] = c;
	vector->dim[3] = 0;
	return (vector);
}