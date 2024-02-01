/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:57:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/01 21:42:02 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

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

int	read_byte(char *str)
{
	size_t	i;
	int		byte;

	if (ft_strlen(str) > 3)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	byte = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		byte *= 10;
		byte += str[i] - '0';
		i++;
	}
	return (byte);
}

int	read_color(char *str, t_color *color)
{
	char	**split;
	int		byte;
	int		error;

	split = ft_split(str, ',');
	if (split == NULL)
		return (0);
	if (word_length(split) != 3)
		return (0);
	error = 1;
	byte = read_byte(split[0]);
	if (byte == 0)
		error = 0;
	color->r = byte;
	byte = read_byte(split[1]);
	if (byte == 0)
		error = 0;
	color->g = byte;
	byte = read_byte(split[2]);
	if (byte == 0)
		error = 0;
	color->b = byte;
	free(split);
	return (error);
}

int	read_double(char *str, double *number)
{
	size_t	i;
	int		d;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != '.' && ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}