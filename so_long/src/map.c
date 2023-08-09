/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:34:54 by rrault            #+#    #+#             */
/*   Updated: 2023/06/05 10:34:55 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_map(char *str, t_data *data)
{
	char	*stock;
	int		read_bytes;
	int		fd;

	stock = (char *)malloc(sizeof(char) * 4096 + 1);
	if (!stock)
		return ;
	str = ft_strjoin("maps/", str);
	fd = open(str, O_RDONLY);
	read_bytes = read(fd, stock, 4096);
	if (read_bytes == -1)
	{
		free(stock);
		return ;
	}
	stock[read_bytes] = '\0';
	data->level = ft_split(stock);
	store_map2(data);
	if (valide_map(data) == 0)
		check(data, stock);
	else
		errorfree(data);
	free(stock);
	free(str);
}

void	store_image(t_data *data)
{
	int	s;

	s = 64;
	data->image.player[0] = mlx_xpm_file_to_image
		(data->mlx, "image/player.xpm", &s, &s);
	data->image.player[1] = mlx_xpm_file_to_image
		(data->mlx, "image/player_l.xpm", &s, &s);
	data->image.player[2] = mlx_xpm_file_to_image
		(data->mlx, "image/player_d.xpm", &s, &s);
	data->image.player[3] = mlx_xpm_file_to_image
		(data->mlx, "image/player_r.xpm", &s, &s);
	data->image.wall = mlx_xpm_file_to_image
		(data->mlx, "image/wall.xpm", &s, &s);
	data->image.item = mlx_xpm_file_to_image
		(data->mlx, "image/item.xpm", &s, &s);
	data->image.enemy[0] = mlx_xpm_file_to_image
		(data->mlx, "image/enemy_b.xpm", &s, &s);
	data->image.enemy[1] = mlx_xpm_file_to_image
		(data->mlx, "image/enemy_r.xpm", &s, &s);
	data->image.door = mlx_xpm_file_to_image
		(data->mlx, "image/door.xpm", &s, &s);
	data->image.openex = mlx_xpm_file_to_image
		(data->mlx, "image/openex.xpm", &s, &s);
	data->image.floor = mlx_xpm_file_to_image
		(data->mlx, "image/floor.xpm", &s, &s);
}

void	print_image(t_data *data, t_image *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, image, x * 64, y * 64);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == '1')
				print_image(data, data->image.wall, x, y);
			else if (data->level[y][x] == '0')
				print_image(data, data->image.floor, x, y);
			else if (data->level[y][x] == 'C')
				print_image(data, data->image.item, x, y);
			else if (data->level[y][x] == 'P')
				print_image(data, data->image.player[0], x, y);
			else if (data->level[y][x] == 'E')
				print_image(data, data->image.door, x, y);
			else if (data->level[y][x] == 'M')
				print_image(data, data->image.enemy[0], x, y);
			x++;
		}
		y++;
	}
}

void	map_size(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->level[y])
		y++;
	while (data->level[1][x])
		x++;
	data->size_y = y;
	data->size_x = x;
}
