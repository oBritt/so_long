/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:22:28 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/03 11:18:25 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rect(char **map, int len)
{
	int	it2;
	int	it1;
	int	l;

	l = -1;
	it1 = 0;
	while (it1 < len)
	{
		it2 = 0;
		while (map[it1][it2] != 0 && map[it1][it2] != '\n')
			it2++;
		if (map[it1][it2 - 1] != '1' || map[it1][0] != '1')
			return (0);
		if (l == -1)
			l = it2;
		if (it2 != l)
			return (0);
		it1++;
	}
	if (!check_all_ones(map[0]) || !check_all_ones(map[len - 1]))
		return (0);
	return (1);
}

void	set_cords(char **map, int *cords)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				cords[0] = x;
				cords[1] = y;
			}
			if (map[y][x] == 'E')
			{
				cords[2] = x;
				cords[3] = y;
			}
			x++;
		}
		y++;
	}
}

int	full_check(char **map)
{
	int	len;
	int	cords[6];

	len = 0;
	while (map[len])
		len++;
	if (len < 3)
		return (0);
	if (!check_chars(map))
		return (0);
	if (!check_rect(map, len))
		return (0);
	if (!check_for_p_e(map, 0, 0))
		return (0);
	if (!check_c(map, 0, 0))
		return (0);
	set_cords(map, cords);
	get_len_h(map, cords, len);
	if (!check_path(map, cords))
		return (0);
	return (1);
}
