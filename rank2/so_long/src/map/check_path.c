/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 14:39:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/30 12:48:05 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Fills the map with 1's until it has encountered a wall */
void	find_path(t_game *game, int x, int y)
{
	if (game->temp_grid[x][y] == 'E')
	{
		game->temp_grid[x][y] = '1';
		return ;
	}
	else if (game->temp_grid[x][y] == '1')
		return ;
	game->temp_grid[x][y] = '1';
	find_path(game, x - 1, y);
	find_path(game, x + 1, y);
	find_path(game, x, y - 1);
	find_path(game, x, y + 1);
}

/* Checks if the exit is accessible */
void	check_path(t_map map, t_game *game)
{
	char	**temp_grid;
	int		i;

	i = 0;
	temp_grid = (char **)malloc(map.height * sizeof(char *));
	if (!temp_grid)
		ft_error("Malloc\n");
	while (i < map.height)
	{
		temp_grid[i] = ft_strdup(map.map[i]);
		i++;
	}
	game->temp_grid = temp_grid;
	find_path(game, map.start_x, map.start_y);
	if (temp_grid[map.exit_x][map.exit_y] != '1')
		ft_error("No valid path\n");
	check_path_collectibles(game);
}

/* Checks if all the collectibles are accessible */
void	check_path_collectibles(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.map[x][y] == 'C')
			{
				if (game->temp_grid[x][y] != '1')
					ft_error("Collectible not reachable\n");
			}
			y++;
		}
		x++;
	}
}

/* Fills the map with 1's until it has encountered a wall or enemy */
void	find_path_enemy(t_game *game, int x, int y)
{
	if (game->temp_grid[x][y] == 'X' || game->temp_grid[x][y] == '1')
		return ;
	game->temp_grid[x][y] = '1';
	find_path_enemy(game, x - 1, y);
	find_path_enemy(game, x + 1, y);
	find_path_enemy(game, x, y - 1);
	find_path_enemy(game, x, y + 1);
}

/* Checks if the only path possible is blocked by an enemy */
void	check_path_enemies(t_game *game)
{
	char	**temp_grid;
	int		i;

	i = 0;
	game->temp_grid = NULL;
	temp_grid = (char **)malloc(game->map.height * sizeof(char *));
	if (!temp_grid)
		ft_error("Malloc\n");
	while (i < game->map.height)
	{
		temp_grid[i] = ft_strdup(game->map.map[i]);
		if (!temp_grid[i])
			ft_error("Strdup\n");
		i++;
	}
	game->temp_grid = temp_grid;
	find_path_enemy(game, game->map.start_x, game->map.start_y);
	if (temp_grid[game->map.exit_x][game->map.exit_y] != '1')
		remove_enemies(game);
}
