/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:17:39 by rrault            #+#    #+#             */
/*   Updated: 2023/06/09 09:17:40 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_pos2(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == 'M')
			{
				data->pos_enemy[data->enemycount] = y;
				data->pos_enemx[data->enemycount] = x;
				data->enemycount++;
			}
			x++;
		}
		y++;
	}
}

void	enemy_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->enemycount = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == 'M')
			{
				data->enemycount++;
			}
			x++;
		}
		y++;
	}
	data->pos_enemy = (int *)malloc(sizeof(int) * data->enemycount + 1);
	data->pos_enemx = (int *)malloc(sizeof(int) * data->enemycount + 1);
	data->enemycount = 0;
	enemy_pos2(data);
}
