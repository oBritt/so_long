/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:41:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 12:04:37 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	separate2(t_data *data, char **map, int x, int y)
{
	if (map[y][x] == 'e')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->escape_a, x * MULTI, y * MULTI);
	if (map[y][x] == 'S')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->player_s, x * MULTI, y * MULTI);
	if (map[y][x] == 'M')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->monster_d, x * MULTI, y * MULTI);
	if (map[y][x] == 'm')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->monster_u, x * MULTI, y * MULTI);
	if (map[y][x] == 'O')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->monster_l, x * MULTI, y * MULTI);
	if (map[y][x] == 'o')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->monster_r, x * MULTI, y * MULTI);
}

void	separate(t_data *data, char **map, int x, int y)
{
	if (map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->player_d, x * MULTI, y * MULTI);
	if (map[y][x] == 'p')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->player_u, x * MULTI, y * MULTI);
	if (map[y][x] == 'L')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->player_l, x * MULTI, y * MULTI);
	if (map[y][x] == 'l')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->player_r, x * MULTI, y * MULTI);
	if (map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->wall, x * MULTI, y * MULTI);
	if (map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->escape, x * MULTI, y * MULTI);
	if (map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->colect, x * MULTI, y * MULTI);
	if (map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->nothing, x * MULTI, y * MULTI);
	separate2(data, map, x, y);
}
