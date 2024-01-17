/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:50 by rrault            #+#    #+#             */
/*   Updated: 2024/01/17 14:09:12 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animated_enemy(t_data *data)
{
	int	i;

	i = data->enemycount;
	data->global_frame++;
	if (data->global_frame > 18000)
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

int    animated_player(t_data *data)
{
    data->global_frame2++;
    while (data->global_frame2 > 18000)
    {
        data->player_frame++;
        if (data->player_frame > 1)
            data->player_frame = 0;
        mlx_put_image_to_window(data->mlx,
            data->win, data->image.player2[data->player_frame],
            data->player2_x * 64, data->player2_y * 64);
        data->global_frame2 = 0;
    }
    return (0);
}
