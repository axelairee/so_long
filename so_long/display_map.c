/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:45:18 by abolea            #+#    #+#             */
/*   Updated: 2024/01/17 16:40:00 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_wall(t_game	*val)
{
	int	i;
	int	j;

	i = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == '1')
				mlx_put_image_to_window(val->mlx, val->win, val->img_wall, j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_ground(t_game *val, int i, int j)
{
	i = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == '0')
				mlx_put_image_to_window(val->mlx, val->win, val->img_ground, j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_collec(t_game *val)
{
	int	i;
	int	j;;

	i = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == 'C')
				mlx_put_image_to_window(val->mlx, val->win, val->img_collec, j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (1);
}

int put_player(t_game *val)
{
    mlx_put_image_to_window(val->mlx, val->win, val->img_player, val->pos_x * 50, val->pos_y * 50);
    return (1);
}

int put_playeru(t_game *val)
{
    mlx_put_image_to_window(val->mlx, val->win, val->img_playeru, val->pos_x * 50, val->pos_y * 50);
    return (1);
}

int put_playerl(t_game *val)
{
    mlx_put_image_to_window(val->mlx, val->win, val->img_playerl, val->pos_x * 50, val->pos_y * 50);
    return (1);
}

int put_playerd(t_game *val)
{
    mlx_put_image_to_window(val->mlx, val->win, val->img_playerd, val->pos_x * 50, val->pos_y * 50);
    return (1);
}

int	put_exit(t_game	*val)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == 'E')
				mlx_put_image_to_window(val->mlx, val->win, val->img_exit1, j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_exit2(t_game *val)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == 'E')
				mlx_put_image_to_window(val->mlx, val->win, val->img_exit, j * 50, i * 50);
			j++;
		}
		i++;
	}
	return (1);
}
