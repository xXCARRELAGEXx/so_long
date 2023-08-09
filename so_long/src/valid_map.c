/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:23:22 by rrault            #+#    #+#             */
/*   Updated: 2023/06/12 10:23:27 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_wall2(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->level[y])
	{
		while (data->level[y][x])
			if (data->level[y][x++] != '1')
				return (1);
		y++;
	}
	y--;
	x = 0;
	while (data->level[y][x])
		if (data->level[y][x++] != '1')
			return (1);
	return (0);
}

int	valid_wall1(t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (data->level[y])
	{
		if (data->level[y][0] != '1')
			i = 1;
		x = 0;
		while (data->level[y][x])
			x++;
		x--;
		if (data->level[y][x] != '1')
			i = 1;
		y++;
	}
	if (i == 1 || valid_wall2(data) == 1)
		return (write(1, "Error\n\tMissing wall\n", 20));
	return (0);
}

int	valid_item(t_data *data)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (c < 1)
		return (write(1, "Error\n\tMissing item\n", 20));
	return (0);
}

int	valid_playerandexit(t_data *data)
{
	int	x;
	int	y;
	int	p;
	int	e;

	y = 0;
	e = 0;
	p = 0;
	while (data->level[y])
	{
		x = -1;
		while (data->level[y][++x])
		{
			if (data->level[y][x] == 'P')
				p++;
			else if (data->level[y][x] == 'E')
				e++;
		}
		y++;
	}
	if (p != 1 || e != 1)
		return (write(1, "Error\n\tInvalid number of player or exit\n", 40));
	return (0);
}
