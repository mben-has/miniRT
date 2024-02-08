/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:14:43 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 22:15:26 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_color	*color_add(t_color *a, t_color *b, t_garbage_collector *gc)
{
	t_color	*result;

	result = (t_color *) malloc(sizeof(t_color));
	if (result == NULL)
		exit_function(gc, "error allocating color\n", 1, true);
	else
		add_pointer_node(gc, result);
	result->col[0] = a->col[0] + b->col[0];
	result->col[1] = a->col[1] + b->col[1];
	result->col[2] = a->col[2] + b->col[2];
	return (result);
}
