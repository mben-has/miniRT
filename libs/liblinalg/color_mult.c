/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:25:58 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 20:10:55 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_color	*color_mult(t_color *a, double c)
{
	t_color	*result;

	result = (t_color *) malloc(sizeof(t_color));
	if (result == NULL)
		return (NULL);
	result->col[0] = c * a->col[0];
	result->col[1] = c * a->col[1];
	result->col[2] = c * a->col[2];
	return (result);
}
