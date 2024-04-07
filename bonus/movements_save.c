/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:48:21 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/07 14:35:06 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win_lose(t_data *data, char **map, int x, int y)
{
	if (map[y][x] == 'e')
		winner(data, 1);
	if (is_monster(map[y][x]))
		winner(data, 0);
}
