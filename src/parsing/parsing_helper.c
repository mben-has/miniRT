/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:57:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/08 22:39:51 by mben-has         ###   ########.fr       */
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
	byte = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		byte *= 10;
		byte += str[i] - '0';
		i++;
	}
	if (byte < range_left || byte > range_right)
		return (-1);
	return (byte);
}

int	read_color(char *str, t_vector_p **color, t_garbage_collector *gc)
{
	char	**split;
	int		byte;
	int		error;

	// malloc struct
	*color = (t_vector_p *) malloc(sizeof(t_vector_p));
	if (*color == NULL)
		return (0);
    // add_pointer_node(gc, *color);

	split = ft_split(str, ',');
	if (split == NULL)
		return (0);
	if (word_length(split) != 3)
		return (free_2d(split), 0);
	error = 1;
	byte = read_byte(split[0], 0, 255);
	if (byte == -1)
		error = 0;
	(*color)->coordinate[0] = byte;
	byte = read_byte(split[1], 0, 255);
	if (byte == -1)
		error = 0;
	(*color)->coordinate[1] = byte;
	byte = read_byte(split[2], 0, 255);
	if (byte == -1)
		error = 0;
	(*color)->coordinate[2] = byte;
	free_2d(split);
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

int	read_double(char *str, double *number, double range_left, double range_right)
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
	if (range_left != 0 && range_right != 0 && (*number < range_left || *number > range_right))
		return (0);
	return (1);
}

int	read_vector(char *str, t_vector_p **vector, int is_normal, t_garbage_collector *gc)
{
	char	**split;
	int		error;
	int		range_left;
	int		range_right;

	// maloc struct
	*vector = (t_vector_p *) malloc(sizeof(t_vector_p));
	if (*vector == NULL)
		return (0);
    // add_pointer_node(gc, *vector);

	// split string
	split = ft_split(str, ',');
	if (split == NULL)
		return (0);
	if (word_length(split) != 3)
		return (free_2d(split), 0);

	// set range
	range_left = 0;
	range_right = 0;
	if (is_normal)
	{
		range_left = -1.0;
		range_right = 1.0;
	}

	// read in doubles
	error = 1;
	if (read_double(split[0], &(*vector)->coordinate[0], range_left, range_right) == 0)
		error = 0;
	if (read_double(split[1], &(*vector)->coordinate[1], range_left, range_right) == 0)
		error = 0;
	if (read_double(split[2], &(*vector)->coordinate[2], range_left, range_right) == 0)
		error = 0;

	free_2d(split);
	return (error);
}