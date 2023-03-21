/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 13:17:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/20 17:04:14 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**check_command(char	*str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\'')
			return (ft_split_quote(str, '\''));
		else if (str[index] == '"')
			return (ft_split_quote(str, '"'));
		index++;
	}
	return (ft_split_quote(str, ' '));
}

void	output(char *output, char *cmd, t_pipex pipex)
{
	int		output_file;
	char	*path;

	output_file = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output_file < 0)
		error_exit("File couldn't be opened");
	if (access(output, R_OK) != 0 || access(output, W_OK) != 0)
		error_exit("Can't be read/written");
	dup2(output_file, 1);
	path = get_cmd_path(pipex.paths, cmd);
	if (!path)
		error_exit("Command not found");
	if (execve(path, check_command(cmd), pipex.full_envp) == -1)
		error_exit("Execve Error");
}

void	child_process(int fds[], t_pipex pipex)
{
	char	*path;

	if (pipex.infile < 0)
	{
		ft_putstr_fd("pipex: input: No such file or directory\n", 2);
		exit(0);
	}
	close(fds[0]);
	dup2(fds[1], 1);
	path = get_cmd_path(pipex.paths, pipex.cmd);
	if (!path)
		error_exit("Command not found");
	if (execve(path, pipex.cmd_split, pipex.full_envp) == -1)
	{
		ft_putstr_fd("Execve Error", 2);
		exit(127);
	}
}

void	main_loop(t_pipex pipex)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) < 0)
		error_exit("Error with opening the pipe");
	pid = fork();
	if (pid < 0)
		error_exit("Error with fork");
	if (pid == 0)
	{
		child_process(fds, pipex);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], 0);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int		index;
	int		status;
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	index = 2;
	pipex.infile = open(argv[1], O_RDONLY);
	dup2(pipex.infile, 0);
	check_envp(&pipex, envp);
	while (index < argc - 2)
	{
		pipex.cmd = argv[index];
		pipex.cmd_split = check_command(argv[index]);
		main_loop(pipex);
		index++;
	}
	output(argv[argc - 1], argv[index], pipex);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (EXIT_FAILURE);
}