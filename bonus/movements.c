/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:28:43 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 14:12:14 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	winner(t_data *data, int i)
{
	mlx_destroy_image(data->mlx, data->player_d);
	mlx_destroy_image(data->mlx, data->player_u);
	mlx_destroy_image(data->mlx, data->player_l);
	mlx_destroy_image(data->mlx, data->player_r);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->escape);
	mlx_destroy_image(data->mlx, data->colect);
	mlx_destroy_image(data->mlx, data->nothing);
	mlx_destroy_image(data->mlx, data->escape_a);
	mlx_destroy_image(data->mlx, data->player_s);
	mlx_destroy_image(data->mlx, data->monster_d);
	mlx_destroy_image(data->mlx, data->monster_u);
	mlx_destroy_image(data->mlx, data->monster_r);
	mlx_destroy_image(data->mlx, data->monster_l);
	freeing(data->map);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	if (i == 2)
		write(1, "You have closed the game\n", 25);
	else if (i == 1)
		write(1, "Congrats you have won\n", 22);
	else
		write(1, "Unfortunally you have lost\n", 27);
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
	data->cur_x = x;
	check_win_lose(data, map, x, y);
	if (map[y][x] == 'C')
	{
		map[y][x] = 'S';
		data->amount -= 1;
	}
	else
		map[y][x] = 'L';
	change_gate(data);
	random_move(data);
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
	check_win_lose(data, map, x, y);
	if (map[y][x] == 'C')
	{
		map[y][x] = 'S';
		data->amount -= 1;
	}
	else
		map[y][x] = 'l';
	change_gate(data);
	random_move(data);
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
	check_win_lose(data, map, x, y);
	if (map[y][x] == 'C')
	{
		map[y][x] = 'S';
		data->amount -= 1;
	}
	else
		map[y][x] = 'p';
	change_gate(data);
	random_move(data);
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
	check_win_lose(data, map, x, y);
	if (map[y][x] == 'C')
	{
		map[y][x] = 'S';
		data->amount -= 1;
	}
	else
		map[y][x] = 'P';
	change_gate(data);
	random_move(data);
	output(data);
}
