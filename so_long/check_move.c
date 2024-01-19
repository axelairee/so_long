/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:27:54 by abolea            #+#    #+#             */
/*   Updated: 2024/01/19 16:47:54 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	keypressed(int keycode, void *param)
{
	t_game	*val;

	val = (t_game *)param;
	key_select(keycode, val);
	put_px(val);
	mlx_string_put(val->mlx, val->win, 30, 34, 0x000000, "move : ");
	mlx_string_put(val->mlx, val->win, 75, 34, 0x000000, ft_itoa(val->move));
	mlx_string_put(val->mlx, val->win, 95, \
	34, 0x000000, "remaining collectibles : ");
	mlx_string_put(val->mlx, val->win, 240, 34, 0x000000, ft_itoa(val->nb_c));
	return (1);
}
