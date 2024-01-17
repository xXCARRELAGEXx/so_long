/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:05:29 by rrault            #+#    #+#             */
/*   Updated: 2024/01/17 17:01:43 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player2_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x++])
		{
			if (data->level[y][x] == 'J')
			{
				data->player2_x = x;
				data->player2_y = y;
			}
		}
		y++;
	}
}

int	iswall2(t_data *data, int x, int y)
{
	if (data->level[y][x] == '1' || data->level[y][x] == 'M'
		|| (data->level[y][x] == 'E'))
		return (1);
	else if (data->level[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.victory,
		7 * 64, 4 * 64);
		mlx_do_sync(data->mlx);
		write(1, "GG the police, you arrested the second player\n", 46);
		sleep(4);
		quit(data);
	}
	else if (data->map[data->player2_y][data->player2_x] == 'C')
	{
		
		mlx_put_image_to_window(data->mlx, data->win, data->image.item,
			data->player2_x * 64, data->player2_y * 64);
		return (0);
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
			data->player2_x * 64, data->player2_y * 64);
	data->steps2++;
	put_steps2(data);
	return (0);
}

int	rotate2(t_data *data, int x, int y, int i)
{
	data->player2_y += y;
	data->player2_x += x;
	return (i);
}
