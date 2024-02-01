/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:16:02 by marschul          #+#    #+#             */
/*   Updated: 2023/10/09 20:57:13 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	char	*pointer;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	pointer = dst + dst_len;
	size = size - dst_len;
	while (size > 1 && *src != '\0')
	{
		*pointer = *src;
		pointer++;
		src++;
		size--;
	}
	*pointer = '\0';
	return (src_len + dst_len);
}
