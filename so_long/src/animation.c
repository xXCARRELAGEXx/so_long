/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:50 by rrault            #+#    #+#             */
/*   Updated: 2023/06/08 16:12:50 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animated_enemy(t_data *data)
{
	int	i;

	i = data->enemycount;
	data->global_frame++;
	if (data->global_frame > 9000)
	{
		data->enemy_frame++;
		if (data->enemy_frame > 1)
			data->enemy_frame = 0;
		while (i--)
			mlx_put_image_to_window(data->mlx,
				data->win, data->image.enemy[data->enemy_frame],
				data->pos_enemx[i] * 64, data->pos_enemy[i] * 64);
		data->global_frame = 0;
	}
	return (0);
}
