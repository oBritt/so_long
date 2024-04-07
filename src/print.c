/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:58:36 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/07 15:52:10 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_nbr(int n)
{
	char	c;

	if (n)
	{
		c = n % 10 + '0';
		put_nbr(n / 10);
		write(1, &c, 1);
	}
}

void	print(int n)
{
	write(1, "You made your: ", 15);
	put_nbr(n);
	write(1, " move\n", 6);
}

int	helper_f(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	return (0);
}
