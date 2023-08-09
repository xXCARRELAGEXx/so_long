/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:59:16 by rrault            #+#    #+#             */
/*   Updated: 2023/06/06 15:59:18 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x++])
		{
			if (data->level[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			else if (data->level[y][x] == 'C')
				data->itemcount++;
			else if (data->level[y][x] == 'E')
			{
				data->doorx = x;
				data->doory = y;
			}
		}
		y++;
	}
	data->countitem++;
}

int	iswall(t_data *data, int x, int y)
{
	if (data->level[y][x] == '1'
		|| (data->level[y][x] == 'E' && data->itemcount > 0))
		return (1);
	else if (data->level[y][x] == 'E' && data->itemcount == 0)
	{
		write(1, "You escaped the police ! Nice job.\n", 35);
		quit(data);
	}
	else if (data->level[y][x] == 'M')
	{
		write(1, "You have been arrested, good luck for the prison.\n", 50);
		quit(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
		data->player_x * 64, data->player_y * 64);
	data->steps++;
	put_steps(data);
	return (0);
}

void	check_item(t_data *data)
{
	if (data->level[data->player_y][data->player_x] == 'C')
	{
		data->itemcount--;
		data->level[data->player_y][data->player_x] = '0';
		if (data->itemcount == 0)
			mlx_put_image_to_window(data->mlx,
				data->win, data->image.openex,
				data->doorx * 64, data->doory * 64);
	}
}

int	rotate(t_data *data, int x, int y, int i)
{
	data->player_y += y;
	data->player_x += x;
	return (i);
}

int	handle_input(int keysym, t_data *data)
{
	int	i;

	i = -1;
	if (keysym == XK_Escape)
		quit(data);
	else if (keysym == 119 && (iswall
			(data, data->player_x, data->player_y - 1) == 0))
		i = rotate(data, 0, -1, 0);
	else if (keysym == 97 && (iswall
			(data, data->player_x - 1, data->player_y) == 0))
		i = rotate(data, -1, 0, 1);
	else if (keysym == 115 && (iswall
			(data, data->player_x, data->player_y + 1) == 0))
		i = rotate(data, 0, 1, 2);
	else if (keysym == 100 && (iswall
			(data, data->player_x + 1, data->player_y) == 0))
		i = rotate(data, 1, 0, 3);
	if (i != -1)
		mlx_put_image_to_window(data->mlx,
			data->win, data->image.player[i],
			data->player_x * 64, data->player_y * 64);
	check_item(data);
	return (0);
}
