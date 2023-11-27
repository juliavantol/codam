/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_structs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 12:44:31 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/28 00:18:51 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	free_redirection(t_filenames *node)
{
	if (node != NULL)
	{
		if (node->filename != NULL)
			free(node->filename);
		if (node->delimiter != NULL)
			free(node->delimiter);
		free(node);
	}
}

void	reset_executor(t_exe *executor)
{
	free(executor->pids);
	executor->pids = NULL;
	free_command_list(executor);
}

int	ctrl_d(t_exe *executor)
{
	free(executor->input);
	exit(EXIT_SUCCESS);
}
