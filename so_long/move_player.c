/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:46:45 by abolea            #+#    #+#             */
/*   Updated: 2024/01/19 16:17:24 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_select(int keycode, t_game *val)
{
	if (keycode == 65307)
		close_window(val);
	if (keycode == 119)
	{
		val->pos_y -= 1;
		move_up(val);
	}
	if (keycode == 115)
	{
		val->pos_y += 1;
		move_down(val);
	}
	if (keycode == 97)
	{
		val->pos_x -= 1;
		move_left(val);
	}
	if (keycode == 100)
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
		return ;
	}
	if (sup_player(val) == 1)
	{
		printmap(val);
	}
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
		return ;
	}
	if (sup_player(val) == 1)
	{
		printmap(val);
	}
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
		return ;
	}
	if (sup_player(val) == 1)
	{
		printmap(val);
	}
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
		return ;
	}
	if (sup_player(val) == 1)
	{
		printmap(val);
	}
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
