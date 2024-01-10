/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:05:08 by abolea            #+#    #+#             */
/*   Updated: 2024/01/10 16:40:23 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line.h"

typedef struct game
{
	char	**map;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
}	t_game;

size_t	ft_strlen(const char *s);
int		get_col(char *name, t_game *test);
int		get_map(char *name, t_game *val);
int		wall_error(t_game *val);
int		check_name(char *name);
int		return_error(char *name, t_game *val);
int		check_player(t_game *val);
int		check_exit(t_game *val);
int		check_collec(t_game *val);
void	free_map(t_game *val);
int		check_strdup(char *line, int fd, t_game *val);
int		check_way(t_game *val);
void	flood_fill(char **copy, int x, int y);

#endif