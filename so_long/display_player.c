/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:26:40 by abolea            #+#    #+#             */
/*   Updated: 2024/01/19 17:00:38 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_player(t_game *val)
{
	mlx_put_image_to_window(val->mlx, val->win, \
	val->img_player, val->pos_x * 50, val->pos_y * 50);
	return (1);
}

int	put_playeru(t_game *val)
{
	mlx_put_image_to_window(val->mlx, val->win, \
	val->img_playeru, val->pos_x * 50, val->pos_y * 50);
	return (1);
}

int	put_playerl(t_game *val)
{
	mlx_put_image_to_window(val->mlx, val->win, \
	val->img_playerl, val->pos_x * 50, val->pos_y * 50);
	return (1);
}

int	put_playerd(t_game *val)
{
	mlx_put_image_to_window(val->mlx, val->win, \
	val->img_playerd, val->pos_x * 50, val->pos_y * 50);
	return (1);
}

void	destroy_image(t_game *val)
{
	mlx_destroy_image(val->mlx, val->img_collec);
	mlx_destroy_image(val->mlx, val->img_exit1);
	mlx_destroy_image(val->mlx, val->img_exit);
	mlx_destroy_image(val->mlx, val->img_ground);
	mlx_destroy_image(val->mlx, val->img_player);
	mlx_destroy_image(val->mlx, val->img_playerd);
	mlx_destroy_image(val->mlx, val->img_playeru);
	mlx_destroy_image(val->mlx, val->img_playerl);
	mlx_destroy_image(val->mlx, val->img_wall);
}
