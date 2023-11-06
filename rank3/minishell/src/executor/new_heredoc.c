/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_heredoc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/05 18:08:12 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/06 02:17:40 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	signal_received;

static void heredoc_signal_handler(int signal)
{
    if (signal == SIGINT)
    {
		signal_received = 1;
		exit(1);
	}
}

void init_heredoc_signal_handler(void) {
    signal(SIGINT, heredoc_signal_handler);
}

void	fill_heredoc_file(char *filename, t_filenames *input_file)
{
	char	*input;
	int		file;

	file = open_file(filename, TRUNCATE);
	input_file->filename = ft_strdup(filename);
	input = NULL;
	while (signal_received == 0)
	{
		signal(SIGINT, heredoc_signal_handler);
		input = readline("> ");
		if (ft_strcmp(input, input_file->delimiter))
			break ;
		input = join_three_strs(input, NULL, "\n");
		write(file, input, ft_strlen(input));
		free(input);
	}
	close(file);
	signal(SIGINT, SIG_DFL);
}

void	start_heredoc(t_filenames *input_file)
{
	int		pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		fill_heredoc_file(input_file->filename, input_file);
		exit(0);	
	}
	waitpid(pid, &status, 0);
	if (status != 0)
		signal_received = 1;
}

void	handle_heredocs(t_exe *executor)
{
	t_cmd		*head;
	t_filenames	*input_head;
	int			index;

	head = executor->commands_list;
	index = 0;
	ignore_signals();
	while (head != NULL && signal_received == 0)
	{
		input_head = head->inputs;
		while (input_head != NULL && signal_received == 0)
		{
			if (input_head->mode == HEREDOC)
				start_heredoc(input_head);
			input_head = input_head->next;
		}
		index++;
		head = head->next;
	}
	restore_signals();
}
