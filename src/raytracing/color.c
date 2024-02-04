/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: BigBen <BigBen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:08:10 by BigBen            #+#    #+#             */
/*   Updated: 2024/02/04 10:27:42 by BigBen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Minirt.h"
t_color *init_color(t_vector *colors, t_ray **ray, t_garbage_collector *gc)
{
    t_color *color;
    color = malloc(sizeof(t_color));
    if (!color)
        exit_function(gc, "error while alloc color", 1, true);
    else
        add_pointer_node(gc, color);
    color->v_color = init_vector(colors->coordinate[0],\
    colors->coordinate[1],\
    colors->coordinate[2], gc);
    
    return (color);
}