/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 14:20:49 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/25 16:49:38 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player(t_game *game)
{
	// mlx_image_t	*temp;
	int			x_old;
	int			y_old;

	x_old = game->player_img->instances[0].x;
	y_old = game->player_img->instances[0].y;
	printf("%d\n", game->loop);
	if (game->loop < 3)
		game->loop += 1;
	else
		game->loop = 1;
	// temp = get_picture(game->mlx, "textures/grandma/down2.png");
	// mlx_delete_image(game->mlx, game->player_img);
	// put_image(game->mlx, temp, x_old, y_old);
	// game->player_img = temp;
	// game->player_img->instances[0].x = x_old;
	// game->player_img->instances[0].y = y_old;

}

void	check_collision(t_game	*game)
{
	int			x_player;
	int			y_player;
	t_mouse		*mouse;

	x_player = game->player_img->instances[0].x;
	y_player = game->player_img->instances[0].y;
	mouse = game->mice;
	while (mouse != NULL)
	{
		if (mouse->img->instances[0].x == x_player
			&& mouse->img->instances[0].y == y_player)
			close_window();
		mouse = mouse -> next;
	}
}

/* Will move the player on the board. 1 for up, 2 for down
3 for left, 4 for right */
void	move_player(t_game *game, char	*path, int x, int y)
{
	mlx_image_t	*temp;
	int			x_old;
	int			y_old;

	temp = get_picture(game->mlx, path);
	x_old = game->player_img->instances[0].x / PIXELS;
	y_old = game->player_img->instances[0].y / PIXELS;
	game->map.map[y_old][x_old] = '0';
	mlx_delete_image(game->mlx, game->player_img);
	put_image(game->mlx, temp, x, y);
	game->player_img = temp;
	game->player_img->instances[0].x = x;
	game->player_img->instances[0].y = y;
	game->map.map[y / PIXELS][x / PIXELS] = 'P';
}

int	check_move(t_game *game, int key)
{
	int		x;
	int		y;

	x = game->player_img->instances[0].x;
	y = game->player_img->instances[0].y;
	if (key == MLX_KEY_LEFT || key == MLX_KEY_A)
		x -= PIXELS;
	else if (key == MLX_KEY_RIGHT || key == MLX_KEY_D)
		x += PIXELS;
	else if (key == MLX_KEY_UP || key == MLX_KEY_W)
		y -= PIXELS;
	else if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
		y += PIXELS;
	x = x / PIXELS;
	y = y / PIXELS;
	if (game->map.map[y][x] == 'C')
		found_collectible(game, x, y);
	if ((game->map.map[y][x] == 'E' && check_status(game) == 1))
		close_window();
	else if (game->map.map[y][x] == 'E' || game->map.map[y][x] == '1')
		return (0);
	return (1);
}
