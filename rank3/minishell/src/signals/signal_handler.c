/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signal_handler.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:48:34 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/07 14:05:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include <readline/readline.h>
#include <readline/history.h>

int	signal_code;

void	signal_handler(int signal_num)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	signal_code = 128 + signal_num;
	(void) signal_num;
}

void	init_signal_handler(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	rl_catch_signals = 0;
}

void	ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	restore_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
