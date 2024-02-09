/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:19:14 by mben-has          #+#    #+#             */
/*   Updated: 2024/02/08 21:33:46 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/garbage_collector.h"

void	exit_function(t_garbage_collector *collector, char *string,
	int exit_code, bool should_exit)
{
	if (string)
		printf("%s\n", string);
	if (should_exit)
	{
		free_all(collector);
		system("leaks minirt");
		exit(exit_code);
	}
}
