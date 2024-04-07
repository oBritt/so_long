/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:43:10 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/07 14:28:10 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**freeing(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	copy(char **temp, char **map, char *t)
{
	int	i;

	i = 0;
	while (map[i])
	{
		temp[i] = map[i];
		i++;
	}
	temp[i] = t;
	temp[i + 1] = NULL;
	free(map);
}

char	**get_it(int fd, int len)
{
	char	**map;
	char	**temp;
	char	*t;

	map = malloc(1 * sizeof(char *));
	if (!map)
		return (NULL);
	map[0] = NULL;
	while (1)
	{
		len++;
		t = get_next_line(fd);
		if (!t)
			return (freeing(map));
		if (!(*t))
			break ;
		temp = malloc(len * sizeof(char *));
		if (!temp)
			return (freeing(map));
		copy(temp, map, t);
		map = temp;
	}
	free(t);
	return (map);
}

char	**get_map(char *link)
{
	int		fd;
	char	**map;
	int		i;

	i = 0;
	while (link[i])
		i++;
	if (i < 5)
		return (NULL);
	if (link[i - 1] != 'r' || link[i - 2] != 'e' || link[i - 3] != 'b' \
	|| link[i - 4] != '.')
		return (NULL);
	fd = open(link, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = get_it(fd, 1);
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}
