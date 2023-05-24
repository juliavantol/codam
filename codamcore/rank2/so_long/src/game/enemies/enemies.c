/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemies.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 12:24:06 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/24 12:35:19 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_enemies(t_game *game)
{
	t_mouse			*mouse;

	mouse = game->mice;
	while (mouse != NULL)
	{
		printf("%d\n", mouse -> test);
		mouse = mouse -> next;
	}
}


void	add_enemy(t_game *game, mlx_image_t *img)
{
	t_mouse	*last;
	t_mouse	*new;

	last = game->mice;
	new = malloc(sizeof(t_mouse));
	new -> img = img;
	new -> next = NULL;
	if (game->mice == NULL)
	{
		new -> next = NULL;
		game->mice = new;
	}
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		last -> next = new;
	}
}

void	move_enemies(void *data)
{
	t_mouse		*mouse;
	t_game		*game;
	static int	runs;

	game = (t_game *)data;
	mouse = game->mice;
	check_collision(game);
	if (runs++ < ENEMY_SPEED)
		return ;
	while (mouse != NULL)
	{
		try_move(mouse, game, 0, 0);
		mouse = mouse -> next;
	}
	runs = 0;
}

void	add_enemies(t_game *game)
{
	mlx_image_t		*mouse;
	int				x;
	int				y;

	game->mice = NULL;
	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == 'X')
			{
				mouse = get_picture(game->mlx, "textures/mouse/right2.png");
				add_enemy(game, mouse);
				put_image(game->mlx, mouse, x * PIXELS, y * PIXELS);
			}
			y++;
		}
		x++;
	}
}