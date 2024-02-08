/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:14:43 by marschul          #+#    #+#             */
/*   Updated: 2024/02/07 20:08:45 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_color	*color_add(t_color *a, t_color *b)
{
	t_color	*result;

	result = (t_color *) malloc(sizeof(t_color));
	if (result == NULL)
		return (NULL);
	result->col[0] = a->col[0] + b->col[0];
	result->col[1] = a->col[1] + b->col[1];
	result->col[2] = a->col[2] + b->col[2];
	return (result);
}
