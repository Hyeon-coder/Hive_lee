#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"

# define TILE_SIZE 64
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

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
	int		tile_size;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	void	*img_floor;
}	t_game;

// map_reader.c
char	**read_map(char *filename, int *width, int *height);
void	free_map(char **map, int height);

// map_validator.c
int		validate_map(t_game *game);
int		check_map_elements(t_game *game);

// render.c
void	render_map(t_game *game);
void	load_images(t_game *game);

// events.c
int		handle_keypress(int keycode, t_game *game);
int		handle_exit(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

// utils.c
void	error_exit(char *message);
void	cleanup_game(t_game *game);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif 