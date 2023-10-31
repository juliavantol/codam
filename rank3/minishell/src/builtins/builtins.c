/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/09 23:18:10 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/31 14:26:25 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

bool	check_builtin(t_exe *executor, t_cmd *command)
{
	char	**name;
	int		index;

	index = 0;
	name = ft_split(command->command_name, ' ');
	while (executor->builtins[index].command)
	{
		printf("%s\n", executor->builtins[index].command);
		if (ft_strcmp(name[0], executor->builtins[index].command))
		{
			executor->builtins[index].function(executor, command);
			// return (true);
		}
		index++;
	}
	printf("index: %d\n", index);
	exit(1);
	if (ft_strcmp(name[0], "exit")
		&& executor->index == executor->command_count - 1)
	{
		empty_array(name);
		exit_shell(executor, EXIT_SUCCESS);
	}
	empty_array(name);
	return (false);
}

char	*get_current_directory(void)
{
	char	*path;

	path = ft_malloc(PATH_MAX + 1);
	getcwd(path, PATH_MAX + 1);
	return (path);
}

void	cd(t_exe *executor, t_cmd *command)
{
	int		return_value;
	char	**path;
	char	*pwd;

	path = ft_split(command->command_name, ' ');
	return_value = chdir(path[1]);
	if (return_value != 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path[1], STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("");
	}
	else
	{
		free(executor->current_directory);
		pwd = get_current_directory();
		executor->current_directory = pwd;
		export(executor, "PWD", pwd);
	}
	empty_array(path);
}

void	print_current_directory(t_exe *executor, t_cmd *command)
{
	printf("%s\n", executor->current_directory);
	(void)command;
}

void	exit_shell(t_exe *executor, int code)
{
	empty_executor(executor);
	exit(code);
}

void	echo(t_exe *executor, t_cmd *command)
{
	char	**str;
	int		i;
	char	*value;
	bool	newline;

	i = 1;
	str = ft_split(command->command_name, ' ');
	newline = true;
	while (detact_newline_flag(str[i]))
		i++;
	if (i != 1)
		newline = false;
	while (str[i])
	{
		value = get_variable(executor, str[i]);
		if (value)
			printf("%s", value);
		else
			printf("%s", str[i]);
		i++;
		if (str[i])
			printf(" ");
	}
	if (newline == true)
		printf("\n");
	empty_array(str);
}
