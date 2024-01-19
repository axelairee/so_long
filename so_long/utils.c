/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:25:10 by abolea            #+#    #+#             */
/*   Updated: 2024/01/19 17:00:20 by abolea           ###   ########.fr       */
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

void	put_px(t_game *val)
{
	int	i;
	int	j;

	i = 0;
	while (i < 240)
	{
		j = 0;
		while (j < 20)
		{
			mlx_pixel_put(val->mlx, val->win, 20 + i, 20 + j, 0xCCCCCC);
			j++;
		}
		i++;
	}
}

int	close_window(t_game *val)
{
	mlx_clear_window(val->mlx, val->win);
	mlx_destroy_window(val->mlx, val->win);
	free_map(val);
	destroy_image(val);
	free(val->mlx);
	free(val->win);
	return (1);
}
