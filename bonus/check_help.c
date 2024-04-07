/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:42:13 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/04 12:02:30 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(char **map)
{
	int		i;
	int		i1;
	char	c;

	i = 0;
	while (map[i])
	{
		i1 = 0;
		while (map[i][i1] && map[i][i1] != '\n')
		{
			c = map[i][i1];
			if (!(c == '1' || c == 'P' || c == 'C' || c == 'E' || c == '0' \
			|| c == 'M'))
				return (0);
			i1++;
		}
		i++;
	}
	return (1);
}

int	transform(int x, int y, int lenx)
{
	return (y * lenx + x);
}

void	solving(char **map, int	*cor, int *visited)
{
	if (map[cor[1]][cor[0]] == '1')
		return ;
	if (visited[transform(cor[0], cor[1], cor[4])])
		return ;
	visited[transform(cor[0], cor[1], cor[4])] = 1;
	if (cor[0] <= 0 || cor[1] <= 0 || cor[0] >= cor[4] || cor[1] >= cor[5])
		return ;
	if (map[cor[1]][cor[0]] == 'E')
		return ;
	cor[0] += 1;
	solving(map, cor, visited);
	cor[0] -= 2;
	solving(map, cor, visited);
	cor[0] += 1;
	cor[1] += 1;
	solving(map, cor, visited);
	cor[1] -= 2;
	solving(map, cor, visited);
	cor[1] += 1;
}

int	check_if_visited(char **map, int *cords, int *visited)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if ((map[y][x] == 'C' || map[y][x] == 'E') && \
			!visited[transform(x, y, cords[4])])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_path(char **map, int *cords)
{
	int	*visited;
	int	i;

	visited = malloc(cords[4] * cords[5] * sizeof(int));
	if (!visited)
		return (0);
	i = 0;
	while (i < cords[4] * cords[5])
		visited[i++] = 0;
	solving(map, cords, visited);
	i = check_if_visited(map, cords, visited);
	free(visited);
	return (i);
}
