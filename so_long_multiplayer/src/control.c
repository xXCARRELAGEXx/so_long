/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:59:16 by rrault            #+#    #+#             */
/*   Updated: 2024/01/17 16:57:20 by rrault           ###   ########.fr       */
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
			else if (data->level[y][x] == 'J')
			{
				data->player2_x = x;
				data->player2_y = y;
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

// void test(t_data *data)
// {
// 	sleep(4);
// 	quit(data);
// }

int	iswall(t_data *data, int x, int y)
{
	if (data->level[y][x] == '1'
		|| (data->level[y][x] == 'E' && data->itemcount > 0))
		return (1);
	else if (data->level[y][x] == 'E' && data->itemcount == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.defeat,
		7 * 64, 4 * 64);
		mlx_do_sync(data->mlx);
		write(1, "GG the thief, you escaped the second player\n", 44);
		sleep(4);
		quit(data);
	}
	else if (data->level[y][x] == 'M')
	{
		write(1, "You have been arrested, good luck for the prison.\n", 50);
		quit(data);
	}
	else if (data->level[y][x] == 'J')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.victory,
		7 * 64, 4 * 64);
		mlx_do_sync(data->mlx);
		write(1, "GG the police, you arrested the second player\n", 46);
		sleep(4);
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
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->itemcount--;
		data->map[data->player_y][data->player_x] = '0';
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
	int j;

	i = -1;
	j = -1;
	if (keysym == XK_Escape)
		quit(data);
	else if (keysym == 119 && (iswall
			(data, data->player_x, data->player_y - 1) == 0))
		{
			data->level[data->player_y - 1][data->player_x] = 'P';
			data->level[data->player_y][data->player_x] = '0';
			i = rotate(data, 0, -1, 0);

		}
	else if (keysym == 97 && (iswall
			(data, data->player_x - 1, data->player_y) == 0))
		{
			data->level[data->player_y][data->player_x - 1] = 'P';
			data->level[data->player_y][data->player_x] = '0';
			i = rotate(data, -1, 0, 1);
		}
	else if (keysym == 115 && (iswall
			(data, data->player_x, data->player_y + 1) == 0))
		{
			data->level[data->player_y + 1][data->player_x] = 'P';
			data->level[data->player_y][data->player_x] = '0';
			i = rotate(data, 0, 1, 2);
		}
	else if (keysym == 100 && (iswall
			(data, data->player_x + 1, data->player_y) == 0))
		{
			data->level[data->player_y][data->player_x + 1] = 'P';
			data->level[data->player_y][data->player_x] = '0';
			i = rotate(data, 1, 0, 3);
		}
	else if (keysym == 65362 && (iswall2
			(data, data->player2_x, data->player2_y - 1) == 0))
		{
			data->level[data->player2_y - 1][data->player2_x] = 'J';
			data->level[data->player2_y][data->player2_x] = '0';
			j = rotate2(data, 0, -1, 0);
		}
	else if (keysym == 65361 && (iswall2
			(data, data->player2_x - 1, data->player2_y) == 0))
		{
			data->level[data->player2_y][data->player2_x - 1] = 'J';
			data->level[data->player2_y][data->player2_x] = '0';
			j = rotate2(data, -1, 0, 1);
		}
	else if (keysym == 65364 && (iswall2
			(data, data->player2_x, data->player2_y + 1) == 0))
		{
			data->level[data->player2_y + 1][data->player2_x] = 'J';
			data->level[data->player2_y][data->player2_x] = '0';
			j = rotate2(data, 0, 1, 2);
		
		}
	else if (keysym == 65363 && (iswall2
			(data, data->player2_x + 1, data->player2_y) == 0))
		{	
			data->level[data->player2_y][data->player2_x + 1] = 'J';
			data->level[data->player2_y][data->player2_x] = '0';
			j = rotate2(data, 1, 0, 3);
			
		}
	if (i != -1)
		mlx_put_image_to_window(data->mlx,
			data->win, data->image.player[i],
			data->player_x * 64, data->player_y * 64);
	if (j != -1)
		mlx_put_image_to_window(data->mlx,
			data->win, data->image.player2[j],
			data->player2_x * 64, data->player2_y * 64);
	check_item(data);
	return (0);
}
