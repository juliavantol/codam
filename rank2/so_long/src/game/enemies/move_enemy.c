/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 12:22:19 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/30 12:11:24 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Moves the enemy */
void	move_enemy(t_mouse *mouse, t_game *game, int y, int x)
{
	mlx_image_t	*temp;

	temp = NULL;
	if (mouse->x == 0 && mouse->y == -1)
		temp = get_picture(game->mlx, "textures/mouse/up2.png");
	else if (mouse->x == 1 && mouse->y == 0)
		temp = get_picture(game->mlx, "textures/mouse/right2.png");
	else if (mouse->x == -1 && mouse->y == 0)
		temp = get_picture(game->mlx, "textures/mouse/left2.png");
	else if (mouse->x == 0 && mouse->y == 1)
		temp = get_picture(game->mlx, "textures/mouse/down2.png");
	if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'P')
	{
		game->map.map[mouse->img->instances[0].y
			/ PIXELS][mouse->img->instances[0].x / PIXELS] = '0';
		mlx_delete_image(game->mlx, mouse->img);
		put_image(game->mlx, temp, y * PIXELS, x * PIXELS);
		mouse->img = temp;
		game->map.map[y][x] = 'X';
	}
}

/* Tries to find a valid direction for the enemy to go to */
void	try_move(t_mouse *mouse, t_game *game, int y, int x)
{
	int	try;

	try = 0;
	while (try < 5)
	{
		mouse->x = (rand() % 3) - 1;
		mouse->y = (rand() % 3) - 1;
		if ((mouse->x - mouse->y) == 1 || (mouse->x - mouse->y) == -1)
		{
			y = (mouse->img->instances[0].y + (mouse->y * PIXELS)) / PIXELS;
			x = (mouse->img->instances[0].x + (mouse->x * PIXELS)) / PIXELS;
			if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'P')
			{
				move_enemy(mouse, game, y, x);
				return ;
			}
			try++;
		}
		else
			try++;
	}
}

/* Functions is called for every frame. Checks if the player 
has collided with an enemy, animates the player and moves all the mice */
void	loops(void *data)
{
	t_mouse		*mouse;
	t_game		*game;

	game = (t_game *)data;
	mouse = game->mice;
	check_collision(game);
	if (game->runs++ < ENEMY_SPEED)
		return ;
	animate_player(game, NULL, game->player_img->instances[0].x,
		game->player_img->instances[0].y);
	while (mouse != NULL)
	{
		try_move(mouse, game, 0, 0);
		mouse = mouse->next;
	}
	game->runs = 0;
}
