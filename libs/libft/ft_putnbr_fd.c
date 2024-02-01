/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:50:15 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 10:31:35 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		str[11];
	int			i;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	i = 10;
	while (nbr != 0)
	{
		str[i--] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	i++;
	while (i < 11)
		ft_putchar_fd(str[i++], fd);
}
