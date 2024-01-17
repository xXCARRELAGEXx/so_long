/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:34:38 by rrault            #+#    #+#             */
/*   Updated: 2023/06/13 09:34:40 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	item_pos2(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->countitem = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == 'C')
			{
				data->item[data->countitem].pos_itemy = y;
				data->item[data->countitem].pos_itemx = x;
				data->item[data->countitem].trigger = 0;
				data->countitem++;
			}
			x++;
		}
		y++;
	}
}

void	item_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->countitem = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == 'C')
			{
				data->countitem++;
			}
			x++;
		}
		y++;
	}
	data->item = (t_item *)malloc(sizeof(t_item) * data->countitem + 1);
	item_pos2(data);
	data->countitem = 0;
}
