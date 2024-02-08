/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:53:35 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 19:57:27 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

double	dot(t_vector *a, t_vector *b)
{
	double		result;

	result = a->dim[0] * b->dim[0];
	result += a->dim[1] * b->dim[1];
	result += a->dim[2] * b->dim[2];
	result += a->dim[3] * b->dim[3];
	return (result);
}
