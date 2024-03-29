/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 02:27:35 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/09 02:58:52 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	loop_args(t_pipex *pipex, char **argv, int argc, int index)
{
	while (index < argc - 2)
	{
		pipex->cmd = argv[index];
		pipex->cmd_split = ft_split_args(argv[index]);
		pipes(*pipex);
		free_cmd_split(pipex);
		index++;
	}
	pipex->cmd = argv[index];
	pipex->cmd_split = ft_split_args(argv[index]);
	output(argv[argc - 1], argv[index], *pipex);
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	int		index;
	t_pipex	pipex;

	index = 3;
	if (check_input(argv, argc) == 0)
	{
		index = 2;
		pipex.infile = open(argv[1], O_RDONLY);
		dup2(pipex.infile, 0);
	}
	else
		here_doc(argv[2]);
	get_envp(&pipex, envp);
	loop_args(&pipex, argv, argc, index);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
