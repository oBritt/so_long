/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:50:52 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 13:05:06 by obrittne         ###   ########.fr       */
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

int	destroy_monster(t_data *data)
{
	if (data->monster_d)
		mlx_destroy_image(data->mlx, data->monster_d);
	if (data->monster_l)
		mlx_destroy_image(data->mlx, data->monster_l);
	if (data->monster_r)
		mlx_destroy_image(data->mlx, data->monster_r);
	if (data->monster_u)
		mlx_destroy_image(data->mlx, data->monster_u);
	return (0);
}

int	destroy_all_pic(t_data *data)
{
	if (data->player_d)
		mlx_destroy_image(data->mlx, data->player_d);
	if (data->player_u)
		mlx_destroy_image(data->mlx, data->player_u);
	if (data->player_l)
		mlx_destroy_image(data->mlx, data->player_l);
	if (data->player_r)
		mlx_destroy_image(data->mlx, data->player_r);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->colect)
		mlx_destroy_image(data->mlx, data->colect);
	if (data->escape)
		mlx_destroy_image(data->mlx, data->escape);
	if (data->nothing)
		mlx_destroy_image(data->mlx, data->nothing);
	if (data->escape_a)
		mlx_destroy_image(data->mlx, data->escape_a);
	if (data->player_s)
		mlx_destroy_image(data->mlx, data->player_s);
	return (destroy_monster(data));
}

int	get_pics(t_data *data)
{
	int	c;

	c = MULTI;
	data->player_d = mlx_png_file_to_image(data->mlx, PLAYER_D, &c, &c);
	data->player_u = mlx_png_file_to_image(data->mlx, PLAYER_U, &c, &c);
	data->player_l = mlx_png_file_to_image(data->mlx, PLAYER_L, &c, &c);
	data->player_r = mlx_png_file_to_image(data->mlx, PLAYER_R, &c, &c);
	data->player_s = mlx_png_file_to_image(data->mlx, PLAYER_S, &c, &c);
	data->wall = mlx_png_file_to_image(data->mlx, WALL, &c, &c);
	data->colect = mlx_png_file_to_image(data->mlx, COLECT, &c, &c);
	data->escape = mlx_png_file_to_image(data->mlx, ESCAPE, &c, &c);
	data->nothing = mlx_png_file_to_image(data->mlx, NOTHING, &c, &c);
	data->escape_a = mlx_png_file_to_image(data->mlx, ESCAPE_A, &c, &c);
	data->monster_d = mlx_png_file_to_image(data->mlx, MONSTER_D, &c, &c);
	data->monster_u = mlx_png_file_to_image(data->mlx, MONSTER_U, &c, &c);
	data->monster_l = mlx_png_file_to_image(data->mlx, MONSTER_L, &c, &c);
	data->monster_r = mlx_png_file_to_image(data->mlx, MONSTER_R, &c, &c);
	if (!data->player_d || !data->wall || !data->colect || !data->player_l \
	|| !data->escape || !data->nothing || !data->player_u || !data->player_r \
	|| !data->escape_a || !data->player_s || !data->monster_d || \
	!data->monster_u || !data->monster_l || !data->monster_r)
	{
		return (destroy_all_pic(data));
	}
	return (1);
}
