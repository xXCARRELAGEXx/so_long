/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:19:25 by rrault            #+#    #+#             */
/*   Updated: 2023/06/05 14:19:26 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (0);
	declaration(&data);
	data.mlx = mlx_init();
	store_map(argv[1], &data);
	store_image(&data);
	enemy_pos(&data);
	data.win = mlx_new_window(data.mlx,
			data.size_x * 64, data.size_y * 64 + 32, "Car  vs  police");
	print_map(&data);
	mlx_loop_hook(data.mlx, &animated_enemy, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_hook(data.win, 17, 0, &quit, &data);
	mlx_loop(data.mlx);
	quit(&data);
	return (0);
}
