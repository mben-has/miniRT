/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:58:02 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/21 20:17:32 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage_collector.h"

t_garbage_collector	*init_garbage_collector(void)
{
	t_garbage_collector	*garbage_collector;

	garbage_collector = malloc(sizeof(t_garbage_collector));
	if (garbage_collector == NULL)
		return (NULL);
	garbage_collector->head = NULL;
	garbage_collector->tail = NULL;
	garbage_collector->size = 0;
	return (garbage_collector);
}

t_node_pointer	*create_node(void *pointer)
{
	t_node_pointer	*node_pointer;

	node_pointer = malloc(sizeof(t_node_pointer));
	node_pointer->pointer = pointer;
	return (node_pointer);
}

void	add_pointer_node(t_garbage_collector *garbage_collector, void *pointer)
{
	t_node_pointer	*node_pointer;

	if (pointer)
	{
		node_pointer = create_node(pointer);
		if ((garbage_collector)->head == NULL)
		{
			(garbage_collector)->head = node_pointer;
			(garbage_collector)->tail = node_pointer;
			node_pointer->next = NULL;
			node_pointer->prev = NULL;
		}
		else
		{
			node_pointer->prev = (garbage_collector)->tail;
			(garbage_collector)->tail->next = node_pointer;
			(garbage_collector)->tail = node_pointer;
			node_pointer->next = NULL;
		}
		(garbage_collector)->size++;
	}
	return ;
}

void	free_all(t_garbage_collector *garbage_collector)
{
	t_node_pointer	*aux;
	t_node_pointer	*aux2;

	if (garbage_collector->tail)
		aux = garbage_collector->tail;
	else
		return ;
	while (aux)
	{
		if (aux->pointer)
		{
			ft_free(aux->pointer);
		}
		aux2 = aux;
		aux = aux->prev;
		ft_free(aux2);
		garbage_collector->size--;
	}
	if (garbage_collector)
	{
		free(garbage_collector);
		garbage_collector = NULL;
	}
}
