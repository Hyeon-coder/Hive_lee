/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:38:46 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/02/23 20:25:00 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "get_next_line/get_next_line.h"

# define TILE_SIZE 64

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
int		handle_exit(t_game *game);
int		handle_resize(t_game *game);
void	move_count(t_game *game);

// utils.c
void	free_map(char **map, int height);
void	load_images(t_game *game);
void	init_map(t_game *game, char *map_file);
void	init_window(t_game *game);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif