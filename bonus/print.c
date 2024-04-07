/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:58:36 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 11:34:20 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_nbr(char *t, int n, int i)
{
	char	c;

	if (n)
	{
		c = n % 10 + '0';
		put_nbr(t, n / 10, i - 1);
		t[i] = c;
	}
}

void	print(t_data *data, int n)
{
	char	t[7];

	t[6] = 0;
	t[0] = '0';
	t[1] = '0';
	t[2] = '0';
	t[3] = '0';
	t[4] = '0';
	put_nbr(t, n, 5);
	mlx_string_put(data->mlx, data->win, MULTI * data->blocks_x - 90, \
	17, 0xFFFFFF, "Move: ");
	mlx_string_put(data->mlx, data->win, MULTI * data->blocks_x - 50, \
	17, 0xFFFFFF, t);
}
