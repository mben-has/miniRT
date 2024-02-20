/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:57:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/20 23:49:54 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

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
Helper function for read_double for Norminette reason
*/
long int	read_double_inner_loop(char *str, int *point_position)
{
	size_t		i;
	long int	d;

	d = 0;
	*point_position = -1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (i < ft_strlen(str))
	{
		if (str[i] == '.')
		{
			*point_position = ft_strlen(str) - i - 1;
			i++;
			continue ;
		}
		d *= 10;
		d += str[i] - '0';
		i++;
	}
	if (str[0] == '-')
		d = -d;
	return (d);
}

/*
Reads in double in int or float form. Checks if number is in range.
If both ends of the range are 0, we dont check for range.
*/
bool	read_double(char *str, double *number, double range_left, \
	double range_right)
{
	long int	d;
	double		dec;
	int			point_position;

	if (read_double_check_format(str) == false)
		return (false);
	d = read_double_inner_loop(str, &point_position);
	dec = 1.0f;
	while (point_position-- > 0)
		dec *= 10.0f;
	*number = d / dec;
	if ((!(range_left == 0 && range_right == 0)) && (*number < range_left || \
		*number > range_right))
		return (false);
	return (true);
}

/*
Helper function for read_vector for Norminette reasons
*/
void	set_range(int *range_left, int *range_right, bool is_normal)
{
	*range_left = 0;
	*range_right = 0;
	if (is_normal)
	{
		*range_left = -1.0;
		*range_right = 1.0;
	}
}

/*
Reads in vector, checks if it is in normal range, if it should 
be a normal
*/
bool	read_vector(char *str, t_vector_p **vector, int is_normal, \
	t_garbage_collector *gc)
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
	set_range(&range_left, &range_right, is_normal);
	i = 0;
	while (i < 3)
	{
		if (read_double(split[i], &(*vector)->coordinate[i], range_left, \
			range_right) == false)
			return (false);
		i++;
	}
	free_2d(split);
	return (true);
}
