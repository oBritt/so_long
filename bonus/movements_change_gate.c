/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_change_gate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:34:17 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 11:34:32 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_gate(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	map = data->map;
	if (data->amount == 0)
	{
		y = 0;
		while (map[y])
		{
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] == 'E')
				{
					map[y][x] = 'e';
					return ;
				}
				x++;
			}
			y++;
		}
	}
}
