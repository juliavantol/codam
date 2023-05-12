/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:30:42 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/12 14:25:45 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "include/libft/libft.h"
# include "include/get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# define PIXELS 32

typedef struct s_node
{
	mlx_image_t		*img;
	bool			found;
	struct s_node	*next;
}	t_node;

typedef struct s_map
{
	char	*file;
	char	**map;
	int		width;
	int		height;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		start;
	int		start_x;
	int		start_y;
	int		collectibles;
}	t_map;

typedef struct s_imgs
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player_front;
	mlx_image_t	*player_back;
	mlx_image_t	*player_left;
	mlx_image_t	*player_right;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}	t_imgs;

typedef struct s_game
{
	mlx_image_t	*player_img;
	t_node		*collectibles;
	t_imgs		*pics;
	t_map		map;
	bool		won;
	int			moves;
	mlx_image_t	*display;
	mlx_t		*mlx;
	char		**temp_grid;
	int			exit[2];
}	t_game;

void		ft_error(char *str);
t_map		check_map(int map);
int			if_empty_line(char *str);
void		open_window(t_game game);
int			close_window(void);
char		**fill_map(t_map map_data);
void		print_map(char **map);
t_imgs		set_images(mlx_t *mlx);
void		put_image(mlx_t *mlx, mlx_image_t *img, int x, int y);
int			check_move(t_game *game, int key);
t_node		*new_list(void *content);
void		add_collectible(t_node **collectibles, t_node *new);
mlx_image_t	*get_picture(mlx_t *mlx, char *path);
void		print_list(t_node **collectibles);
void		found_collectible(t_game *game, int x, int y);
int			check_status(t_game *game);
void		display_moves(mlx_t *mlx, t_game *game);
void		fill_grid(t_map map, t_game *game);
void		print_collectibles(t_game game);
void		get_collectibles(t_game *game);
void		put_collectible(mlx_t *mlx, t_game *game, int x, int y);


#endif