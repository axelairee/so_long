/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:46:45 by abolea            #+#    #+#             */
/*   Updated: 2024/01/17 17:20:38 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *val)
{
	mlx_clear_window(val->mlx, val->win);
	mlx_destroy_window(val->mlx, val->win);
	exit(0);
	return (1);
}

void	key_select(int keycode, t_game *val)
{
//	usleep(1);
//	move_enemy(val);
	if (keycode == 65307) //touche esc
		close_window(val);
	if (keycode == 119) //touche w
	{
		val->pos_y -= 1;
		move_up(val);
	}
	if (keycode == 115) //touche s
	{
		val->pos_y += 1;
		move_down(val);
	}
	if (keycode == 97) //touche a
	{
		val->pos_x -= 1;
		move_left(val);
	}
	if (keycode == 100) //touche d
	{
		val->pos_x += 1;
		move_right(val);
	}
}


void	move_up(t_game *val)
{
	if (val->map[val->pos_y][val->pos_x] == '1')
	{
		val->pos_y += 1;
		return;
	}
	if (sup_player(val) == 1)
		printmap(val);	
	if (val->map[val->pos_y][val->pos_x] == 'P')
		put_ground(val, val->pos_y - 1, val->pos_x);
	if (val->map[val->pos_y][val->pos_x] == '0')
	{
		if_wall(val);
		put_playeru(val);
	}
	else if (val->map[val->pos_y][val->pos_x] == 'C')
	{
		if_collec(val);
		put_playeru(val);
	}
	if (val->map[val->pos_y][val->pos_x] == 'E' && val->nb_c == 0)
		close_window(val);
}


void	move_down(t_game *val)
{
	if (val->map[val->pos_y][val->pos_x] == '1')
	{
		val->pos_y -= 1;
		return;
	}	
	if (sup_player(val) == 1)
		printmap(val);	
	if (val->map[val->pos_y][val->pos_x] == 'P')
		put_ground(val, val->pos_y + 1, val->pos_x);
	if (val->map[val->pos_y][val->pos_x] == '0')
	{
		if_wall(val);
		put_playerd(val);
	}
	else if (val->map[val->pos_y][val->pos_x] == 'C')
	{
		if_collec(val);
		put_playerd(val);
	}
	if (val->map[val->pos_y][val->pos_x] == 'E' && val->nb_c == 0)
		close_window(val);
}

void	move_left(t_game *val)
{
	if (val->map[val->pos_y][val->pos_x] == '1')
	{
		val->pos_x += 1;
		return;
	}	
	if (sup_player(val) == 1)
		printmap(val);
	if (val->map[val->pos_y][val->pos_x] == '0')
	{
		if_wall(val);
		put_playerl(val);
	}
	else if (val->map[val->pos_y][val->pos_x] == 'C')
	{
		if_collec(val);
		put_playerl(val);
	}
	else if (val->map[val->pos_y][val->pos_x] == 'E' && val->nb_c == 0)
		close_window(val);
}

void	move_right(t_game *val)
{
	if (val->map[val->pos_y][val->pos_x] == '1')
	{
		val->pos_x -= 1;
		return;
	}		
	if (sup_player(val) == 1)
		printmap(val);	
	if (val->map[val->pos_y][val->pos_x] == 'P')
		put_ground(val, val->pos_y, val->pos_x + 1);	 
	if (val->map[val->pos_y][val->pos_x] == '0')
	{
		if_wall(val);
		put_player(val);
	}
	else if (val->map[val->pos_y][val->pos_x] == 'C')
	{
		if_collec(val);
		put_player(val);
	}
	if (val->map[val->pos_y][val->pos_x] == 'E' && val->nb_c == 0)
		close_window(val);
}

void	if_wall(t_game *val)
{
	put_ground(val, val->pos_y, val->pos_x + 1);
	val->move++;
}

void	if_collec(t_game *val)
{
	val->map[val->pos_y][val->pos_x] = '0';
	printmap(val);
	put_player(val);
	collec_count(val);
	val->move++;
}

int	sup_player(t_game *val)
{
	int	i;
	int	j;

	i = 0;
	while (i < val->height)
	{
		j = 0;
		while (j < val->width)
		{
			if (val->map[i][j] == 'P')
			{
				val->map[i][j] = '0';
				return (1);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	collec_count(t_game *val)
{
	val->nb_c -= 1;
	if (val->nb_c == 0)
		put_exit2(val);
}

int keypressed(int keycode, void *param)
{
    t_game *val = (t_game *)param;
	key_select(keycode, val);
	put_px(val);
	mlx_string_put(val->mlx, val->win, 30, 34, 0x000000, "move : ");
	mlx_string_put(val->mlx, val->win, 75, 34, 0x000000, ft_itoa(val->move));
	mlx_string_put(val->mlx, val->win, 95, 34, 0x000000, "collectibles restants : ");
	mlx_string_put(val->mlx, val->win, 240, 34, 0x000000, ft_itoa(val->nb_c));
	return(1);
}

void	put_px(t_game *val)
{
	int i;
	int j;

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