/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:45:20 by marschul          #+#    #+#             */
/*   Updated: 2024/02/20 16:46:16 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

/*
Checks for file extension .rt.
*/
bool	check_file_extension(char *file)
{
	int	length;

	length = ft_strlen(file);
	if (length < 4 || file[length - 3] != '.' || file[length - 2] != 'r' || \
		file[length - 1] != 't')
		return (false);
	else
		return (true);
}

/*
Checks if camera, light and ambient is unique.
*/
bool	check_for_unique(int i)
{
	static int	unique_elements[3];

	if (i > 2)
		return (1);
	if (unique_elements[i] == 1)
		return (false);
	unique_elements[i] = 1;
	return (true);
}
