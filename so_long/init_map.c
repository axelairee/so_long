/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:46:12 by abolea            #+#    #+#             */
/*   Updated: 2024/01/19 16:22:17 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_col(char *name, t_game *val)
{
	char	*line;
	int		fd;
	int		len;

	val->height = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	len = ft_strlen(line);
	val->width = len;
	while (line != NULL)
	{
		val->height++;
		len = ft_strlen(line);
		if (len != val->width)
			return (free(line), -1);
		val->width = len;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_name(char *name)
{
	size_t	i;

	i = 0;
	while (name[i] != '.')
		i++;
	i++;
	if (name[i] != 'b')
		return (-1);
	i++;
	if (name[i] != 'e')
		return (-1);
	i++;
	if (name[i] != 'r')
		return (-1);
	i++;
	return (1);
}

int	wall_error(t_game *val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (i == 0 && val->map[i][j] != '1')
				return (-1);
			if (i == val->height - 1 && val->map[i][j] != '1')
				return (-1);
			if (j == 0 && val->map[i][j] != '1')
				return (-1);
			if (j == val->width - 1 && val->map[i][j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_map(char *name, t_game *val)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	val->map = (char **)malloc(val->height * sizeof(char *));
	if (!val->map)
		return (free_map(val), -1);
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line != NULL)
	{
		val->map[i] = ft_strdup(line);
		if (!val->map[i])
			check_strdup(line, fd, val);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	return_error(char *name, t_game *val)
{
	if (get_col(name, val) == -1)
		return (-1);
	else if (get_map(name, val) == -1)
		return (free_map(val), -1);
	else if (wall_error(val) == -1)
		return (free_map(val), -1);
	else if (check_name(name) == -1)
		return (free_map(val), -1);
	else if (check_exit(val) == -1)
		return (free_map(val), -1);
	else if (check_player(val) == -1)
		return (free_map(val), -1);
	else if (check_collec(val) == -1)
		return (free_map(val), -1);
	else if (check_way(val) == -1)
		return (free_map(val), -1);
	if (get_map(name, val) == -1)
		return (free_map(val), -1);
	return (1);
}
