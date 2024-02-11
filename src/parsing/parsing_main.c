/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-has <mben-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:45:22 by marschul          #+#    #+#             */
/*   Updated: 2024/02/10 23:32:59 by mben-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

int	init_scene(t_scene *scene)
{
	void *mem;

	mem = (t_sphere *) malloc(100 * sizeof(t_sphere *));
	if (mem == NULL)
		return (0);
	scene->spheres = mem;
	mem = (t_plane *) malloc(100 * sizeof(t_plane *));
	if (mem == NULL)
		return (0);
	scene->planes = mem;
	mem = (t_cylinder *) malloc(100 * sizeof(t_cylinder *));
	if (mem == NULL)
		return (0);
	scene->cylinders = mem;
	scene->nr_spheres = 0;
	scene->nr_planes = 0;
	scene->nr_cylinders = 0;
	return (1);
}

int	check_file_extension(char *file)
{
	int	length;

	
	length = ft_strlen(file);
	if (length < 4 || file[length - 3] != '.' || file[length - 2] != 'r' || file[length - 1] != 't')
		return (0);
	else
		return (1);
}

int	check_for_unique(int i)
{
	static int	unique_elements[3];

	if (i > 2)
		return (1);
	if (unique_elements[i] == 1)
		return (0);
	unique_elements[i] = 1;
	return (1);
}

int	read_in_element(char *line, t_scene *scene, t_garbage_collector *gc)
{
	t_function_pointer	function_pointers[6] = {check_ambient, check_camera, check_light, check_sphere, check_plane, check_cylinder};
	int					i;
	char				**split;

	split = ft_split(line, ' ');
	if (split == NULL)
		return (4);
	i = 0;
	while (i < 6)
	{
		if (function_pointers[i](split, scene, gc) == 1)
		{
			free_2d(split);
			if (check_for_unique(i) == 0)
				return (6);
			else
				return (0);
		}
		i++;
	}
	free_2d(split);
	return (5);
}

int	parsing(char *file, t_scene *scene, t_garbage_collector *gc)
{
	char	*line;
	int		fd;
	int		error;

	// init scene
	if (init_scene(scene) == 0)
		return (7);

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
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			error = read_in_element(line, scene, gc);
		}
		free(line);
		if (error != 0)
			break;
		line = get_next_line(fd);
	}

	//close file
	close(fd);
	return (error);
}