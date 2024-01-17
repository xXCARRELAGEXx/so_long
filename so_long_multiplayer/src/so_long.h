/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:19:47 by rrault            #+#    #+#             */
/*   Updated: 2024/01/17 16:58:59 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "../Mlx/mlx.h"

typedef struct s_item
{
	int		pos_itemy;
	int		pos_itemx;
	int		trigger;
}		t_item;

typedef struct s_image
{
	void	*player[4];
	void	*wall;
	void	*item;
	void	*door;
	void	*openex;
	void	*floor;
	void	*enemy[2];
	void	*player2[4];
	void	*victory;
	void	*defeat;
}		t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_image	image;
	t_item	*item;
	char	**map;
	char	**level;
	int		is_exit;
	int		is_item;
	int		*pos_enemy;
	int		*pos_enemx;
	int		enemy_frame;
	int		player_frame;
	int		global_frame;
	int		global_frame2;
	int		steps;
	int		steps2;
	int		size_y;
	int		size_x;
	int		actual_pos_x;
	int		actual_pos_y;
	int		player2_x;
	int		player2_y;
	int		player_x;
	int		player_y;
	int		enemycount;
	int		countitem;
	int		itemcount;
	int		doorx;
	int		doory;
}		t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	largeur;
	int	hauteur;
	int	color;
}		t_rect;

void	put_steps2(t_data *data);
void	player2_pos(t_data *data);
void	declaration(t_data *data);
void	print_map(t_data *data);
void	store_image(t_data *data);
void	store_map(char *str, t_data *data);
void	map_size(t_data *data);
void	put_steps(t_data *data);
void	enemy_pos(t_data *data);
void	player_pos(t_data *data);
void	enemy_pos(t_data *data);
void	errorfree(t_data *data);
void	check(t_data *data, char *level);
void	freelevel(t_data *data);
void	item_pos(t_data *data);
void	store_map2(t_data *data);
char	**ft_split(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
int		animated_player(t_data *data);
int		rotate2(t_data *data, int x, int y, int i);
int		animated_enemy(t_data *data);
int		handle_input(int keysym, t_data *data);
int		quit(t_data *data);
int		valide_map(t_data *data);
int		valid_playerandexit(t_data *data);
int		valid_item(t_data *data);
int		valid_wall1(t_data *data);
int		iswall2(t_data *data, int x, int y);


#endif
