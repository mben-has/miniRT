/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:33:15 by marschul          #+#    #+#             */
/*   Updated: 2024/02/09 21:49:10 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblinalg.h"

t_color	*color(double a, double b, double c, t_garbage_collector *gc)
{
	t_color	*_color_;

	_color_ = (t_color *) malloc(sizeof(t_color));
	if (_color_ == NULL)
		exit_function(gc, "error allocating color\n", 1, true);
	else
		add_pointer_node(gc, _color_);
	_color_->col[0] = a;
	_color_->col[1] = b;
	_color_->col[2] = c;
	return (_color_);
}
