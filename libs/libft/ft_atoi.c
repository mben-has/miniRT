/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:24:29 by marschul          #+#    #+#             */
/*   Updated: 2023/06/18 19:25:54 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' \
		|| c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	minus;

	while (ft_isspace(*str))
		str++;
	minus = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	nbr = 0;
	while (*str != '\0' && ft_isdigit((int) *str))
	{
		nbr = 10 * nbr;
		nbr += *str - '0';
		str++;
	}
	return (minus * nbr);
}
