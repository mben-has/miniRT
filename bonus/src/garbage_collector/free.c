/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 00:27:10 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/08 21:34:00 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage_collector.h"

void	ft_free(void *to_free)
{
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		ft_free(str[i]);
		i++;
	}
	if (str)
		ft_free(str);
}
