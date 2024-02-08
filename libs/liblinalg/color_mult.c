/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:25:58 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 22:15:46 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_color	*color_mult(t_color *a, double c, t_garbage_collector *gc)
{
	t_color	*result;

	result = (t_color *) malloc(sizeof(t_color));
	if (result == NULL)
		exit_function(gc, "error allocating color\n", 1, true);
	else
		add_pointer_node(gc, result);
	result->col[0] = c * a->col[0];
	result->col[1] = c * a->col[1];
	result->col[2] = c * a->col[2];
	return (result);
}
