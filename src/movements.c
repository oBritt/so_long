/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:28:43 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/07 17:06:41 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	winner(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->escape);
	mlx_destroy_image(data->mlx, data->colect);
	mlx_destroy_image(data->mlx, data->nothing);
	freeing(data->map);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
}

void	go_left(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	x = data->cur_x;
	y = data->cur_y;
	if (map[y][x - 1] == '1' || (map[y][x - 1] == 'E' && data->amount))
		return ;
	map[y][x] = '0';
	data->moves += 1;
	x--;
	if (map[y][x] == 'C')
		data->amount -= 1;
	data->cur_x = x;
	if (map[y][x] == 'E')
		winner(data);
	map[y][x] = 'P';
	print(data->moves);
	output(data);
}

void	go_right(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	x = data->cur_x;
	y = data->cur_y;
	if (map[y][x + 1] == '1' || (map[y][x + 1] == 'E' && data->amount))
		return ;
	map[y][x] = '0';
	data->moves += 1;
	x++;
	data->cur_x = x;
	if (map[y][x] == 'C')
		data->amount -= 1;
	if (map[y][x] == 'E')
		winner(data);
	map[y][x] = 'P';
	print(data->moves);
	output(data);
}

void	go_up(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	x = data->cur_x;
	y = data->cur_y;
	if (map[y - 1][x] == '1' || (map[y - 1][x] == 'E' && data->amount))
		return ;
	map[y][x] = '0';
	data->moves += 1;
	y--;
	data->cur_y = y;
	if (map[y][x] == 'C')
		data->amount -= 1;
	if (map[y][x] == 'E')
		winner(data);
	map[y][x] = 'P';
	print(data->moves);
	output(data);
}

void	go_down(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map;
	x = data->cur_x;
	y = data->cur_y;
	if (map[y + 1][x] == '1' || (map[y + 1][x] == 'E' && data->amount))
		return ;
	map[y][x] = '0';
	data->moves += 1;
	y++;
	data->cur_y = y;
	if (map[y][x] == 'C')
		data->amount -= 1;
	if (map[y][x] == 'E')
		winner(data);
	map[y][x] = 'P';
	print(data->moves);
	output(data);
}
