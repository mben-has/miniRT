/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 06:38:21 by marschul          #+#    #+#             */
/*   Updated: 2023/06/18 18:17:47 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	length;
	int	i;

	length = ft_strlen(s) + 1;
	i = 0;
	while (i < length)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}
