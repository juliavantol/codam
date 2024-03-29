/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:30:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/30 12:51:02 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <sys/errno.h>

# define PIXELS 48
# define ENEMY_SPEED 30

typedef struct s_collect
{
	mlx_image_t			*img;
	bool				found;
	struct s_collect	*next;
}	t_collect;

typedef struct s_mouse
{
	mlx_image_t		*img;
	int				x;
	int				y;
	struct s_mouse	*next;
}	t_mouse;

typedef struct s_tile
{
	int				x;
	int				y;
	bool			enemy;
	struct s_tile	*next;
}	t_tile;

typedef struct s_map
{
	t_tile		*free_tiles;
	char		*file_name;
	char		**map;
	int			collectibles;
	int			tile_count;
	int			width;
	int			height;
	int			file;
	int			exit_x;
	int			exit_y;
	int			exit;
	int			start_x;
	int			start_y;
	int			start;
}	t_map;

typedef struct s_imgs
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player_front;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}	t_imgs;

typedef struct s_game
{
	mlx_image_t	*player_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*display;
	t_mouse		*mice;
	t_collect	*collectibles;
	t_map		map;
	mlx_t		*mlx;
	char		**food_paths;
	char		**temp_grid;
	char		direction;
	int			moves;
	int			runs;
	int			loop;
	bool		won;
}	t_game;

t_map		check_characters(t_map map, int length, char *temp, char *line);
mlx_image_t	*get_picture(mlx_t *mlx, char *path);
t_game		init_game(int file, char *filename);
t_collect	*collectible(void *content);
t_imgs		set_images(mlx_t *mlx);

int			check_walls(t_game game, int i, int j);
int			check_move(t_game *game, int key);
int			check_status(t_game *game);
int			if_empty_line(char *str);

void		valid_character(t_map *data, char *line, int height, int index);
void		prepare_move(t_game *game, mlx_key_data_t key, int x, int y);
void		add_collectible(t_collect **collectibles, t_collect *new);
void		add_tile(t_map *data, t_tile **free_tiles, int x, int y);
void		put_collectible(mlx_t *mlx, t_game *game, int x, int y);
void		animate_player(t_game *game, char *path, int x, int y);
void		put_image(mlx_t *mlx, mlx_image_t *img, int x, int y);
void		move_player(t_game *game, char	*path, int x, int y);
void		try_move(t_mouse *mouse, t_game *game, int i, int j);
void		found_collectible(t_game *game, int x, int y);
void		stop_game(t_game *game, char *msg, int lost);
void		add_enemy(t_game *game, mlx_image_t *img);
void		display_moves(mlx_t *mlx, t_game *game);
void		check_path_collectibles(t_game *game);
void		check_path(t_map map, t_game *game);
void		set_collectible_paths(t_game *game);
void		check_path_enemies(t_game *game);
void		check_collision(t_game	*game);
void		remove_enemies(t_game *game);
void		spawn_enemies(t_game *game);
void		open_window(t_game game);
void		loops(void *data);
void		ft_error(char *str);

#endif
