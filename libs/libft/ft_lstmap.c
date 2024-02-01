/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:26:21 by marschul          #+#    #+#             */
/*   Updated: 2023/10/10 11:36:17 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new;
	void	*new_content;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_content = f(lst->content);
	new = ft_lstnew(new_content);
	if (new == NULL)
	{
		free(new_content);
		return (NULL);
	}
	new->next = ft_lstmap(lst->next, f, del);
	if (lst->next != NULL && new->next == NULL)
	{
		del(new->content);
		free(new);
		return (NULL);
	}
	return (new);
}
