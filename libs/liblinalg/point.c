/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:01:44 by marschul          #+#    #+#             */
/*   Updated: 2024/02/17 10:10:09 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_vector	*point(double a, double b, double c, t_garbage_collector *gc)
{
	t_vector	*point;

	point = (t_vector *) malloc(sizeof(t_vector));
	if (point == NULL)
		exit_function(gc, "error allocating point\n", 1, true);
	else
		add_pointer_node(gc, point);
	point->dim[0] = a;
	point->dim[1] = b;
	point->dim[2] = c;
	point->dim[3] = 1;
	return (point);
}
