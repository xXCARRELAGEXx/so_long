/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:22:00 by rrault            #+#    #+#             */
/*   Updated: 2023/06/12 10:22:10 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valide_map(t_data *data)
{
	if (valid_wall1(data) != 0 || valid_item(data) != 0
		|| valid_playerandexit(data) != 0)
		return (1);
	return (0);
}

void	check_path(t_data *data, int x, int y)
{
	if (x < 0 || x > data->size_x)
		return ;
	if (y < 0 || y > data->size_y)
		return ;
	if (data->is_exit == 1 || !data->level[y][x]
		|| data->level[y][x] == '1' || data->level[y][x] == 'M')
		return ;
	if (data->level[y][x] == 'E')
	{
		if (data->is_exit == 0)
			data->is_exit = 1;
		return ;
	}
	data->level[y][x] = '1';
	check_path(data, x + 1, y);
	check_path(data, x, y - 1);
	check_path(data, x - 1, y);
	check_path(data, x, y + 1);
}

void	check_path_item(t_data *data, int i, int x, int y)
{
	if (x < 0 || x > data->size_x)
		return ;
	if (y < 0 || y > data->size_y)
		return ;
	if (data->item[i].trigger == 1 || !data->level[y][x]
		|| data->level[y][x] == '1' || data->level[y][x] == 'M')
		return ;
	if (data->level[y][x] == 'P')
	{
		data->item[i].trigger = 1;
		return ;
	}
	data->level[y][x] = '1';
	check_path_item(data, i, x + 1, y);
	check_path_item(data, i, x, y - 1);
	check_path_item(data, i, x - 1, y);
	check_path_item(data, i, x, y + 1);
}

void	check2(t_data *data)
{
	int	i;

	i = -1;
	if (data->is_exit == 0)
	{
		write(1, "Error\n\tNo access\n", 17);
		errorfree(data);
	}
	while (++i < data->countitem)
	{
		if (data->item[i].trigger == 0)
		{
			write(1, "Error\n\tNo access item\n", 22);
			errorfree(data);
		}
	}
}

void	check(t_data *data, char *level)
{
	int	i;

	i = -1;
	data->level = ft_split(level);
	check_path(data, data->player_x, data->player_y);
	freelevel(data);
	data->level = ft_split(level);
	while (++i < data->countitem)
	{
		data->level = ft_split(level);
		check_path_item(data, i, data->item[i].pos_itemx,
			data->item[i].pos_itemy);
		freelevel(data);
	}
	data->level = ft_split(level);
	check2(data);
}
