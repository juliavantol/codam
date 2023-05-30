/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 15:17:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/30 10:47:51 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system ("leaks so_long");
}

int	main(int argc, char	**argv)
{
	t_game		game;
	char		*temp;
	int			file;
	int			len;

	// atexit(leaks);
	if (argc != 2)
		ft_error("Not enough arguments\n");
	len = ft_strlen(argv[1] + 4);
	if (!len)
		ft_error("Strlen\n");
	temp = ft_substr(argv[1], len, 4);
	if (!temp)
		ft_error("Substr\n");
	if (ft_strncmp(temp, ".ber", 4) != 0)
		ft_error("File must be a .ber extension\n");
	free(temp);
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		ft_error("File couldn't be opened\n");
	game = init_game(file, argv[1]);
	check_path(game.map, &game);
	close(file);
	open_window(game);
	exit(EXIT_SUCCESS);
}
