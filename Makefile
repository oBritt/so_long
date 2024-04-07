CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix src/, check_help.c check_map.c check_map2.c check_map3.c get_next_line.c get_next_line_utils.c \
	get_stuff.c main.c movements.c print.c so_long.c)

SRCS_B = $(addprefix bonus/, check_help.c check_map.c check_map2.c check_map3.c get_next_line.c get_next_line_utils.c \
	get_stuff.c main.c movements.c movements_change_gate.c movements_monst.c movements_monster.c movements_save.c separate.c print.c so_long.c)

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

NAME = so_long

HEADERS = -I src/so_long.h -I mlx

HEADERS_B = -I bonus/so_long.h -I mlx

NAME_B = so_long_bonus

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) mlx src/so_long.h
	$(MAKE) -C mlx/
	cc $(CFLAGS) $(OBJS) -Lmlx -lmlx -lz -framework OpenGL -framework AppKit $(HEADERS) -o $(NAME)


linux: $(NAME)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) mlx src/so_long.h
	$(MAKE) -C mlx/
	cc $(CFLAGS) $(OBJS) -Lmlx -lmlx -lz -framework OpenGL -framework AppKit $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	$(MAKE) clean -C mlx/
	rm -rf $(NAME)
	rm -rf $(NAME_B)

bonus: $(NAME_B)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $< $(HEADERS_B)

$(NAME_B): $(OBJS_B) mlx bonus/so_long.h
	$(MAKE) -C mlx/
	cc $(CFLAGS) $(OBJS_B) -Lmlx -lmlx -lz -framework OpenGL -framework AppKit $(HEADERS_B) -o $(NAME_B)

re: fclean all

.PHONY: all, clean, fclean, re