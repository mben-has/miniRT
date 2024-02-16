/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:57:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/16 19:44:15 by marschul         ###   ########.fr       */
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
		{
			free_2d(split);
			return (false);
		}
		(*color)->coordinate[i] = byte;	
		i++;
	}
	free_2d(split);
	return (true);
}

/*
Checks if string is int or float format
*/
bool	read_double_check_format(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (i < ft_strlen(str))
	{
		if (str[i] != '.' && ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

/*
Reads in double in int or float form. Checks if number is in range.
If both ends of the range are 0, we dont check for range.
*/
bool	read_double(char *str, double *number, double range_left, double range_right)
{
	size_t		i;
	long int	d;
	double		dec;
	int			point_position;

	if (read_double_check_format(str) == false)
		return (false);
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
		d = -d;
	dec = 1.0f;
	while (point_position-- > 0)
		dec *= 10.0f;
	*number = d / dec;
	if ((!(range_left == 0 && range_right == 0)) && (*number < range_left || *number > range_right))
		return (false);
	return (true);
}

bool	read_vector(char *str, t_vector_p **vector, int is_normal, t_garbage_collector *gc)
{
	char	**split;
	int		i;
	int		range_left;
	int		range_right;

	*vector = (t_vector_p *) malloc(sizeof(t_vector_p));
	if (*vector == NULL)
		return (false);
    add_pointer_node(gc, *vector);
	split = ft_split(str, ',');
	if (split == NULL)
		return (false);
	if (word_length(split) != 3)
		return (free_2d(split), false);
	range_left = 0;
	range_right = 0;
	if (is_normal)
	{
		range_left = -1.0;
		range_right = 1.0;
	}
	i = 0;
	while (i < 3)
	{
		if (read_double(split[i], &(*vector)->coordinate[0], range_left, range_right) == false)
			return (false);
		i++;
	}
	free_2d(split);
	return (true);
}