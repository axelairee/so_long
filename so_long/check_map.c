/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:47 by abolea            #+#    #+#             */
/*   Updated: 2024/01/10 16:39:05 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_game *val)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e != 1)
		return (-1);
	return (1);
}

int	check_player(t_game *val)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == 'P')
			{
				val->pos_x = j;
				val->pos_y = i;
				p++;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		return (-1);
	return (1);
}

int	check_collec(t_game *val)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c < 1)
		return (-1);
	return (c);
}

void	flood_fill(char **copy, int x, int y)
{
	if (copy[x][y] != '1' && copy[x][y] != 'V')
	{
		copy[x][y] = 'V';
		flood_fill(copy, x + 1, y);
		flood_fill(copy, x - 1, y);
		flood_fill(copy, x, y + 1);
		flood_fill(copy, x, y - 1);
	}
}

int	check_way(t_game *val)
{
	flood_fill(val->map, val->pos_x, val->pos_y);
	if (check_collec(val) == -1 && check_exit(val) == -1)
		return (1);
	return (-1);
}
