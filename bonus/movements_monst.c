/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_monst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:23:32 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 14:22:07 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char(char c)
{
	if (c == 'P' || c == 'S' || c == 'p' || c == 'l' || c == 'L')
		return (1);
	return (0);
}

void	monster_r(t_data *data, int x, int y, int numb)
{
	char	**map;

	map = data->map;
	if ((numb != 100))
		map[y][x] = '0';
	if (is_char(map[y][x + 1]))
		winner(data, 0);
	map[y][x + 1] = 'o';
}

void	monster_l(t_data *data, int x, int y, int numb)
{
	char	**map;

	map = data->map;
	if ((numb != 100))
		map[y][x] = '0';
	if (is_char(map[y][x - 1]))
		winner(data, 0);
	map[y][x - 1] = 'O';
}

void	monster_d(t_data *data, int x, int y, int numb)
{
	char	**map;

	map = data->map;
	if (numb != 100)
		map[y][x] = '0';
	if (is_char(map[y + 1][x]))
		winner(data, 0);
	map[y + 1][x] = 'M';
}

void	monster_u(t_data *data, int x, int y, int numb)
{
	char	**map;

	map = data->map;
	if (numb != 100)
		map[y][x] = '0';
	if (is_char(map[y - 1][x]))
		winner(data, 0);
	map[y - 1][x] = 'm';
}
