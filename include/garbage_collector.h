/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:58:29 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/19 15:42:13 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node_pointer
{
	void					*pointer;
	struct s_node_pointer	*next;
	struct s_node_pointer	*prev;
}							t_node_pointer;

typedef struct s_garbage_collector
{
	t_node_pointer			*head;
	t_node_pointer			*tail;
	size_t					size;
}							t_garbage_collector;

t_node_pointer				*create_node(void *pointer);
void						add_pointer_node(t_garbage_collector *gc,
								void *pointer);
t_garbage_collector			*init_garbage_collector(void);
void						free_all(t_garbage_collector *garbage_collector);
bool						exit_function(t_garbage_collector *collector,
								char *string, int exit_code, bool shoul_exit);
void						ft_free(void *to_free);
void						free_2d(char **str);

#endif
