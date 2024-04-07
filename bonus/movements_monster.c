/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_monster.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:45:43 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 14:20:42 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_monster(char c)
{
	if (c == 'O' || c == 'o' || c == 'M' || c == 'm')
		return (1);
	return (0);
}

int	is_other(char c)
{
	if (c == '1' || c == 'E' || c == 'e' || c == 'C')
		return (1);
	return (0);
}
// 0 d u l r

void	make_move(t_data *data, char **map, int y, int x)
{
	int	random;
	int	numb;

	random = rand() % 5;
	if (random == 4 && (is_other(map[y][x + 1]) || is_monster(map[y][x + 1])))
		random--;
	if (random == 3 && (is_other(map[y][x - 1]) || is_monster(map[y][x - 1])))
		random--;
	if (random == 2 && (is_other(map[y - 1][x]) || is_monster(map[y - 1][x])))
		random--;
	if (random == 1 && (is_other(map[y + 1][x]) || is_monster(map[y + 1][x])))
		random--;
	numb = rand() % 500;
	if (random == 4)
		monster_r(data, x, y, numb);
	if (random == 3)
		monster_l(data, x, y, numb);
	if (random == 2)
		monster_u(data, x, y, numb);
	if (random == 1)
		monster_d(data, x, y, numb);
}

void	random_move(t_data *data)
{
	int		y;
	int		x;
	char	**map;

	map = data->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_monster(map[y][x]))
				make_move(data, map, y, x);
			x++;
		}
		y++;
	}
}
