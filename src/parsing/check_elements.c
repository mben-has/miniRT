/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:11:23 by marschul          #+#    #+#             */
/*   Updated: 2024/02/01 14:22:34 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	check_ambient(char *line, t_scene *scene)
{
	if (line[0] == 'A')
	{
		scene->ambient.type = 'A';
		printf("in ambient");
		return (1);
	}
	return (0);
}
