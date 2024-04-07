/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:24:40 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/03 11:18:58 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_2(int i, int e)
{
	if (!i || !e)
		return (0);
	return (1);
}

int	check_for_p_e(char **map, int i, int i1)
{
	int	e;
	int	p;

	e = 0;
	p = 0;
	while (map[i1])
	{
		i = 0;
		while (map[i1][i])
		{
			if (map[i1][i] == 'P' && p)
				return (0);
			else if (map[i1][i] == 'E' && e)
				return (0);
			else if (map[i1][i] == 'P')
				p = 1;
			else if (map[i1][i] == 'E')
				e = 1;
			i++;
		}
		i1++;
	}
	return (check_2(e, p));
}

int	check_c(char **map, int i, int i1)
{
	int	c;

	c = 0;
	while (map[i1])
	{
		i = 0;
		while (map[i1][i])
		{
			if (map[i1][i] == 'C')
				c = 1;
			i++;
		}
		i1++;
	}
	return (check_2(c, 1));
}

void	get_len_h(char **map, int *cords, int len)
{
	int	lenx;

	lenx = 0;
	while (map[0][lenx] != '\n' && map[0][lenx])
		lenx++;
	cords[4] = lenx;
	cords[5] = len;
}
