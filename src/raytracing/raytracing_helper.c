/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:18:02 by marschul          #+#    #+#             */
/*   Updated: 2024/02/13 16:25:27 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

unsigned int	rgb_to_hex(t_color *col)
{
	int	g;
	int	r;
	int	b;
	int	a;

	a = 255;
	r = (int) floor(col->col[0] * 255);
	g = (int) floor(col->col[1] * 255);
	b = (int) floor(col->col[2] * 255);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}
