/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:05:08 by abolea            #+#    #+#             */
/*   Updated: 2024/01/17 17:08:39 by abolea           ###   ########.fr       */
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
	int		nb_c;
	int		move;
    void 	*mlx;
    void 	*win;
	void 	*img_player;
	void 	*img_collec;
	void 	*img_exit;
	void 	*img_exit1;
	void 	*img_ground;
	void 	*img_wall;
	void	*img_playerd;
	void	*img_playeru;
	void	*img_playerl;
	void	*img_end;
	void	*img_enemyl;
	void	*img_enemyr;
	void	*img_enemyu;
	void	*img_enemyd;
	int		epos_x;
	int		epos_y;
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
int		init_window(t_game *val);
void	init_map(t_game *val);
void	key_select(int keycode, t_game *val);
void	move_element(t_game *val, int keycode);
int		keypressed(int keycode, void *param);
int		init_img(t_game *val);
int		printmap(t_game	*val);
int		put_wall(t_game	*val);
int		put_ground(t_game *val, int i, int j);
int		put_player(t_game *val);
int		put_exit(t_game	*val);
int		put_collec(t_game *val);
int		is_valid_move(t_game *val);
int		put_exit2(t_game *val);
void	collec_count(t_game *val);
int		close_window(t_game *val);
int		put_playeru(t_game *val);
int		put_playerd(t_game *val);
int		put_playerl(t_game *val);
void	move_up(t_game *val);
void	move_down(t_game *val);
void	move_left(t_game *val);
void	move_right(t_game *val);
int		sup_player(t_game *val);
void	if_collec(t_game *val);
void	if_wall(t_game *val);
char	*ft_itoa(int n);
void	*ft_calloc(size_t memnb, size_t size);
void	put_px(t_game *val);

#endif