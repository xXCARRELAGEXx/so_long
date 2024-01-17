/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:18:21 by rrault            #+#    #+#             */
/*   Updated: 2024/01/17 17:00:28 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	declaration(t_data *data)
{
	data->steps = 0;
	data->steps2 = 0;
	data->global_frame = 0;
	data->global_frame2 = 0;
	data->enemy_frame = 0;
	data->player_frame = 0;
	data->is_exit = 0;
	data->itemcount = 0;
	data->countitem = 0;
}

void	store_map2(t_data *data)
{
	map_size(data);
	item_pos(data);
	player_pos(data);
}

int	put_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.hauteur)
	{
		j = rect.x;
		while (j < rect.x + rect.largeur)
			mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
		i++;
	}
	return (0);
}

void	put_steps(t_data *data)
{
	char	*str;
	char	*nb;

	nb = ft_itoa(data->steps);
	str = ft_strjoin("Thief's steps : ", nb);
	put_rect(data, (t_rect){0, data->size_y * 64,
		data->size_x * 32, 32, 0xFF6500});
	mlx_string_put(data->mlx, data->win, 14, data->size_y * 64 + 20,
		0xFFFFFF, str);
	free(nb);
	free(str);
}

void	put_steps2(t_data *data)
{
	char	*str;
	char	*nb;

	nb = ft_itoa(data->steps2);
	str = ft_strjoin("Police's steps : ", nb);
	put_rect(data, (t_rect){960, data->size_y * 64,
		data->size_x * 32, 32, 0x0062FF});
	mlx_string_put(data->mlx, data->win, 974, data->size_y * 64 + 20,
		0xFFFFFF, str);
	free(nb);
	free(str);
}