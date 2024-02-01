/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:45:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/01 14:19:49 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	check_file_extension(char *file)
{
	int	length;

	length = ft_strlen(file);
	if (length < 4 || file[length - 3] != '.' || file[length - 2] != 'r' || file[length - 1] != 't')
		return (0);
	else
		return (1);
}

int	read_in_element(char *line, t_scene *scene)
{
	t_function_pointer	function_pointers[6] = {check_ambient};
	int					i;

	i = 0;
	while (i < 1)
	{
		if (function_pointers[i](line, scene) == 1)
			return (0);
		i++;
	}
	return (4);
}

int	parsing(char *file, t_scene *scene)
{
	char	*line;
	int		fd;
	int		error;

	// check for right ending
	if (check_file_extension(file) == 0)
		return (2);

	// open file
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (3);

	// read in lines
	error = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n')
			error = read_in_element(line, scene);
		free(line);
		if (error != 0)
			break;
		line = get_next_line(fd);
	}

	//close file
	close(fd);
	
	return (error);
}