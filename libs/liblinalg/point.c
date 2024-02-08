/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:01:44 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 20:05:41 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*point(double a, double b, double c)
{
	t_vector	*point;

	point = (t_vector *) malloc(sizeof(t_vector));
	if (point == NULL)
		return (NULL);
	point->dim[0] = a;
	point->dim[1] = b;
	point->dim[2] = c;
	point->dim[3] = 1;
	return (point);
}