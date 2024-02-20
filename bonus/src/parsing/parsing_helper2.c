/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:47:59 by marschul          #+#    #+#             */
/*   Updated: 2024/02/20 16:48:37 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

/*
Gives back the number of words in a split
*/
int	word_length(char **split)
{
	int	length;

	length = 0;
	while (*split != NULL)
	{
		length++;
		split++;
	}
	return (length);
}

/*
Reads in one byte. Returns -1 on error. Checks if in range.
*/
int	read_byte(char *str, int range_left, int range_right)
{
	size_t	i;
	int		byte;

	if (ft_strlen(str) > 3)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	byte = atoi(str);
	if (byte < range_left || byte > range_right)
		return (-1);
	return (byte);
}

/*
Reads in color. Uses read_byte. Returns bool for error management.
*/
bool	read_color(char *str, t_vector_p **color, t_garbage_collector *gc)
{
	char	**split;
	int		byte;
	int		i;

	*color = (t_vector_p *) malloc(sizeof(t_vector_p));
	if (*color == NULL)
		return (false);
	add_pointer_node(gc, *color);
	split = ft_split(str, ',');
	if (split == NULL)
		return (false);
	if (word_length(split) != 3)
		return (free_2d(split), false);
	i = 0;
	while (i < 3)
	{
		byte = read_byte(split[i], 0, 255);
		if (byte == -1)
			return (free_2d(split), false);
		(*color)->coordinate[i] = byte;
		i++;
	}
	free_2d(split);
	return (true);
}
