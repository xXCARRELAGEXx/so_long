/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:26 by rrault            #+#    #+#             */
/*   Updated: 2023/06/06 15:58:27 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeall(t_data *data)
{
	int	i;

	i = 0;
	free(data->image.player[0]);
	free(data->image.player[1]);
	free(data->image.player[2]);
	free(data->image.player[3]);
	free(data->image.wall);
	free(data->image.enemy[0]);
	free(data->image.enemy[1]);
	free(data->image.floor);
	free(data->image.door);
	free(data->image.openex);
	free(data->image.item);
	while (data->level[i])
	{
		free(data->level[i]);
		i++;
	}
	free(data->level);
}

void	errorfree(t_data *data)
{
	int	i;

	i = 0;
	while (data->level[i])
	{
		free(data->level[i]);
		i++;
	}
	free(data->level);
	exit(0);
}

int	quit(t_data *data)
{
	freeall(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	freelevel(t_data *data)
{
	int	i;

	while (data->level)
	{
		i = 0;
		while (data->level[i])
			free(data->level[i++]);
		free(data->level);
		data->level = NULL;
	}
}
