/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:41:12 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/07 14:38:55 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_input(int keysym, t_data *data)
{
	if (keysym == 53)
		close_window(data);
	if (keysym == 0)
		go_left(data);
	if (keysym == 2)
		go_right(data);
	if (keysym == 1)
		go_down(data);
	if (keysym == 13)
		go_up(data);
	print(data, data->moves);
	return (0);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	winner(data, 2);
	return (0);
}

void	output(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	map = data->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			separate(data, map, x, y);
			x++;
		}
		y++;
	}
}

void	helper_f(t_data *data)
{
	output(data);
	get_cords(data);
	print(data, 0);
}

int	so_long(char **map)
{
	t_data	data;

	data.map = map;
	get_y_x(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.win = mlx_new_window(data.mlx, data.blocks_x * MULTI, \
	data.blocks_y * MULTI, "Game");
	if (!data.win)
	{
		free(data.mlx);
		return (0);
	}
	if (!get_pics(&data))
	{
		mlx_destroy_window(data.mlx, data.win);
		free(data.mlx);
		return (0);
	}
	helper_f(&data);
	mlx_hook(data.win, 17, 0, &close_window, &data);
	mlx_key_hook(data.win, test_input, &data);
	mlx_loop(data.mlx);
	return (1);
}
