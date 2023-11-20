/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 12:36:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 01:04:35 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "builtins.h"

void	divide_command_in_redirections(t_cmd *node, char *command, int i)
{
	char		**cmd;
	char		*temp;

	cmd = ft_split(command, ' ');
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], ">") && cmd[i + 1])
		{
			node->output_redirection = true;
			add_redirection(&node->outputs, cmd[i + 1], TRUNCATE);
			i++;
		}
		else if (ft_strcmp(cmd[i], ">>") && cmd[i + 1])
		{
			node->output_redirection = true;
			add_redirection(&node->outputs, cmd[i + 1], APPEND);
			i++;
		}
		else if (ft_strcmp(cmd[i], "<") && cmd[i + 1])
		{
			node->input_redirection = true;
			add_redirection(&node->inputs, cmd[i + 1], READ);
			i++;
		}
		else if (ft_strcmp(cmd[i], "<<") && cmd[i + 1])
		{
			node->input_redirection = true;
			add_redirection(&node->inputs, cmd[i + 1], HEREDOC);
			i++;
		}
		else
		{
			temp = ft_strdup(node->command_name);
			free(node->command_name);
			node->command_name = join_three_strs(temp, " ", cmd[i]);
			free(temp);
		}
		i++;
	}
}

void	temp_parser(t_exe *executor, char *input)
{
	char	**command_line_split;
	int		i;

	i = 0;
	command_line_split = ft_split(input, '|');
	executor->commands_list = NULL;
	while (command_line_split[i])
	{
		add_command_node(&executor->commands_list, command_line_split[i], i);
		i++;
	}
	executor->command_count = i;
	executor->pids = ft_malloc((executor->command_count + 1) * sizeof(pid_t));
	executor->index = 0;
	empty_array(command_line_split);
	start_executor(executor);
}
