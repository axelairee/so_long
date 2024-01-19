/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:28:48 by abolea            #+#    #+#             */
/*   Updated: 2024/01/19 16:27:03 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_img(t_game *val)
{
	int	img_height;
	int	img_width;

	img_height = 50;
	img_width = 50;
	val->img_wall = mlx_xpm_file_to_image(val->mlx, "img/wall.xpm", \
	&img_width, &img_height);
	if (val->img_wall == NULL)
		return (-1);
	val->img_ground = mlx_xpm_file_to_image(val->mlx, "img/ground.xpm", \
	&img_width, &img_height);
	if (val->img_ground == NULL)
		return (-1);
	val->img_collec = mlx_xpm_file_to_image(val->mlx, "img/collec.xpm", \
	&img_width, &img_height);
	if (val->img_collec == NULL)
		return (-1);
	val->img_player = mlx_xpm_file_to_image(val->mlx, "img/player.xpm", \
	&img_width, &img_height);
	if (val->img_player == NULL)
		return (-1);
	return (1);
}

int	init_img2(t_game *val)
{
	int	img_height;
	int	img_width;

	img_height = 50;
	img_width = 50;
	val->img_exit = mlx_xpm_file_to_image(val->mlx, "img/exit.xpm", \
	&img_width, &img_height);
	if (val->img_exit == NULL)
		return (-1);
	val->img_exit1 = mlx_xpm_file_to_image(val->mlx, "img/exit1.xpm", \
	&img_width, &img_height);
	if (val->img_exit1 == NULL)
		return (-1);
	val->img_playerd = mlx_xpm_file_to_image(val->mlx, "img/playerd.xpm", \
	&img_width, &img_height);
	if (val->img_playerd == NULL)
		return (-1);
	return (1);
}

int	init_img3(t_game *val)
{
	int	img_height;
	int	img_width;

	img_height = 50;
	img_width = 50;
	val->img_playeru = mlx_xpm_file_to_image(val->mlx, "img/playeru.xpm", \
	&img_width, &img_height);
	if (val->img_playeru == NULL)
		return (-1);
	val->img_playerl = mlx_xpm_file_to_image(val->mlx, "img/playerl.xpm", \
	&img_width, &img_height);
	if (val->img_playerl == NULL)
		return (-1);
	return (1);
}

int	init_window(t_game *val)
{
	val->mlx = mlx_init();
	if (!val->mlx)
		return (-1);
	val->win = mlx_new_window(val->mlx, val->width * 50, \
	val->height * 50, "so_long");
	printmap(val);
	mlx_hook(val->win, 17, 0, close_window, val);
	mlx_key_hook(val->win, keypressed, val);
	mlx_loop(val->mlx);
	return (1);
}

int	printmap(t_game	*val)
{
	if (init_img(val) == -1)
		return (-1);
	else if (init_img2(val) == -1)
		return (-1);
	else if (init_img3(val) == -1)
		return (-1);
	if (put_collec(val) == -1)
		return (-1);
	else if (put_wall(val) == -1)
		return (-1);
	else if (put_ground(val, val->pos_x, val->pos_y) == -1)
		return (-1);
	else if (put_player(val) == -1)
		return (-1);
	else if (put_exit(val) == -1)
		return (-1);
	return (1);
}
