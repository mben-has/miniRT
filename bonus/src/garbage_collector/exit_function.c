/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:19:14 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/16 19:30:31 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage_collector.h"

bool	exit_function(t_garbage_collector *collector, char *string,
	int exit_code, bool should_exit)
{
	if (string)
		printf("%s\n", string);
	if (should_exit)
	{
		free_all(collector);
		exit(exit_code);
	}
	return (false);
}
