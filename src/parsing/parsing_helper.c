/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:57:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/02 17:31:30 by marschul         ###   ########.fr       */
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
		return (-1);
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
	if (byte == -1)
		error = 0;
	color->r = byte;
	byte = read_byte(split[1]);
	if (byte == -1)
		error = 0;
	color->g = byte;
	byte = read_byte(split[2]);
	if (byte == -1)
		error = 0;
	color->b = byte;
	free(split);
	return (error);
}

int	read_double_check_format(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (i < ft_strlen(str))
	{
		if (str[i] != '.' && ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	read_double(char *str, double *number)
{
	size_t		i;
	long int	d;
	double		dec;
	int			point_position;

	if (read_double_check_format(str) == 0)
		return (0);
	d = 0;
	point_position = -1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (i < ft_strlen(str))
	{
		if (str[i] == '.')
		{
			point_position = ft_strlen(str) - i - 1;
			i++;
			continue;
		}
		d *= 10;
		d += str[i] - '0';
		i++;
	}
	if (str[0] == '-')
		d = -1 * d;
	dec = 1.0f;
	while (point_position-- > 0)
		dec *= 10.0f;
	*number = d / dec;
	return (1);
}

int	read_vector(char *str, t_vector *vector)
{
	char	**split;
	int		error;

	split = ft_split(str, ',');
	if (split == NULL)
		return (0);
	if (word_length(split) != 3)
		return (0);
	error = 1;
	if (read_double(split[0], &vector->coordinate[0]) == 0)
		error = 0;
	if (read_double(split[1], &vector->coordinate[1]) == 0)
		error = 0;
	if (read_double(split[2], &vector->coordinate[2]) == 0)
		error = 0;
	free(split);
	return (error);
}