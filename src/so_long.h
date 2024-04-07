/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:37:03 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/07 15:52:45 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

# define MULTI 30

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*player;
	void	*wall;
	void	*colect;
	void	*nothing;
	void	*escape;
	int		blocks_x;
	int		blocks_y;
	int		cur_x;
	int		cur_y;
	int		moves;
	int		amount;
}	t_data;

# define PLAYER "textures/char_d.png"
# define WALL "textures/wall.png"
# define COLECT "textures/colect.png"
# define NOTHING "textures/nothing.png"
# define ESCAPE "textures/escape.png"

char	**get_map(char *link);
char	**freeing(char **str);
int		full_check(char **map);
int		check_chars(char **map);
int		check_for_p_e(char **map, int i, int i1);
int		check_c(char **map, int i, int i1);
int		check_path(char **map, int *cords);
int		check_rect(char **map, int len);
int		so_long(char **map);
int		close_window(void *param);
void	output(t_data *data);
int		helper_f(t_data *data);

void	go_down(t_data *data);
void	go_up(t_data *data);
void	go_left(t_data *data);
void	go_right(t_data *data);
void	winner(t_data *data);
void	print(int n);
void	get_len_h(char **map, int *cords, int len);
void	get_y_x(t_data *data);
void	get_cords(t_data *data);
int		get_pics(t_data *data);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*solve(char *str, char *buffer, int fd);
char	*allocate(char *str);
char	*strjoins(char *first, char *second, char *str);
size_t	get_ind_of_n_len(char *str, int l);
char	*help_delete_25_lines(char *str, char *out, char *second, size_t len1);

#endif