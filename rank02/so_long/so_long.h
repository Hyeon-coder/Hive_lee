/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:54:27 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/05/08 15:48:08 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <mlx.h>
# include "libft/libft.h"

# define TILE_SIZE 32
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

# define PATH_WALL "assets/wall.xpm"
# define PATH_FLOOR "assets/floor.xpm"
# define PATH_PLAYER "assets/player.xpm"
# define PATH_EXIT "assets/exit.xpm"
# define PATH_EXIT_OPEN "assets/exit_open.xpm"
# define PATH_COIN "assets/coin.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		coins;
	int		moves;
	int		exit_x;
	int		exit_y;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_exit_open;
	void	*img_coin;
}	t_game;

void	error_exit(const char *msg);
void	free_map(char **map);
char	**read_map(const char *filename, t_game *game);
void	render_map(t_game *game);
int		handle_input(int keycode, t_game *game);
void	close_game(t_game *game);
int		can_exit(t_game *game);
void	load_images(t_game *game);
void	display_move_count(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		is_valid_extension(const char *filename, const char *ext);
void	validate_not_directory(const char *filename);
void	validate_extension(const char *filename);
void	validate_rectangular(char **map);
void	validate_walls(char **map);
void	validate_elements(char **map);
void	validate_path(t_game *game);
void	count_player_and_coins(char **map, t_game *game);

#endif
