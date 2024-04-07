/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:03:23 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/07 16:50:58 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		map_error();
	map = get_map(argv[1]);
	if (!map)
		map_error();
	if (!full_check(map))
	{
		freeing(map);
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	argc = so_long(map);
	if (!argc)
	{
		freeing(map);
		map_error();
	}
	return (0);
}
