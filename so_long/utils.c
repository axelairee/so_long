/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:10 by abolea            #+#    #+#             */
/*   Updated: 2024/01/16 12:48:36 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *val)
{
	int	i;

	i = 0;
	while (i < val->height)
	{
		free(val->map[i]);
		i++;
	}
	free(val->map);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

int	check_strdup(char *line, int fd, t_game *val)
{
	free(line);
	close(fd);
	free_map(val);
	return (-1);
}
