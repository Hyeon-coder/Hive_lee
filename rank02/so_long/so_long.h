/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:38:46 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/03/11 16:17:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"

# define TILE_SIZE 64
# define MAX_WIDTH (3840 / TILE_SIZE)
# define MAX_HEIGHT (2160 / TILE_SIZE) - 1

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible_before;
	void	*img_collectible_after;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_floor;
}	t_game;

// map_reader.c
char	**read_map(char *filename, int *width, int *height);

// map_validator.c
int		validate_map(t_game *game);

// render.c
void	render_map(t_game *game);
void	put_tile(t_game *game, int x, int y);
void	render_player(t_game *game);

// events.c
int		handle_keypress(int keycode, t_game *game);
void	handle_exit_game(t_game *game, int x, int y);
int		handle_exit(void);
int		handle_resize(t_game *game, int width, int height);
void	move_count(t_game *game);

// handles
int		handle_expose(t_game *game);
void	handle_collectible(t_game *game, int x, int y);

// utils.c
void	free_map(char **map, int height);
void	load_images(t_game *game, int *img_w, int *img_h);
void	init_map(t_game *game, char *map_file);
void	init_window(t_game *game);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif