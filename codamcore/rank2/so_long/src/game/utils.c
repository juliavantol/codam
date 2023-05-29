/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:34:16 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/29 23:17:06 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	if_empty_line(char *str)
{
	int		index;
	size_t	empty;

	index = 0;
	empty = 0;
	if (str[0] == '\n' && ft_strlen(str) == 1)
		return (1);
	while (str[index])
	{
		if (str[index] == ' ')
			empty++;
		index++;
	}
	if (empty == ft_strlen(str))
		return (1);
	return (0);
}

void	stop_game(t_game *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}

void	set_collectible_paths(t_game *game)
{
	char	**food_paths;

	food_paths = (char **)malloc(10 * sizeof(char *));
	if (!food_paths)
		ft_error("Malloc\n");
	food_paths[0] = "textures/food_48/apple1.png";
	food_paths[1] = "textures/food_48/apple2.png";
	food_paths[2] = "textures/food_48/apple3.png";
	food_paths[3] = "textures/food_48/apple4.png";
	food_paths[4] = "textures/food_48/grape1.png";
	food_paths[5] = "textures/food_48/grape2.png";
	food_paths[6] = "textures/food_48/grape3.png";
	food_paths[7] = "textures/food_48/pear1.png";
	food_paths[8] = "textures/food_48/pear2.png";
	food_paths[9] = "textures/food_48/mandarin.png";
	game->food_paths = food_paths;
}
