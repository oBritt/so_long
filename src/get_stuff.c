/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:50:52 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/03 11:51:06 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_y_x(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	data->moves = 0;
	map = data->map;
	y = 0;
	while (map[y][x] && map[y][x] != '\n')
		x++;
	while (map[y])
		y++;
	data->blocks_x = x;
	data->blocks_y = y;
}

void	get_cords(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	data->moves = 0;
	map = data->map;
	y = 0;
	data->amount = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->cur_x = x;
				data->cur_y = y;
			}
			if (map[y][x] == 'C')
				data->amount += 1;
			x++;
		}
		y++;
	}
}

int	get_pics(t_data *data)
{
	int	c;

	c = MULTI;
	data->player = mlx_png_file_to_image(data->mlx, PLAYER, &c, &c);
	data->wall = mlx_png_file_to_image(data->mlx, WALL, &c, &c);
	data->colect = mlx_png_file_to_image(data->mlx, COLECT, &c, &c);
	data->escape = mlx_png_file_to_image(data->mlx, ESCAPE, &c, &c);
	data->nothing = mlx_png_file_to_image(data->mlx, NOTHING, &c, &c);
	if (!data->player || !data->wall || !data->colect \
	|| !data->escape || !data->nothing)
	{
		if (data->player)
			mlx_destroy_image(data->mlx, data->player);
		if (data->wall)
			mlx_destroy_image(data->mlx, data->wall);
		if (data->colect)
			mlx_destroy_image(data->mlx, data->colect);
		if (data->escape)
			mlx_destroy_image(data->mlx, data->escape);
		if (data->nothing)
			mlx_destroy_image(data->mlx, data->nothing);
		return (0);
	}
	return (1);
}
