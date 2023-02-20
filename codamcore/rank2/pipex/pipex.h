/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:18:23 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/02/20 17:46:01 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "includes/libft/libft.h"
# include "includes/printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

char	*get_path(char **envp);
int		run_command(char **paths, char *command);
int		main_loop(char *cmd, int fd_in, char **paths);
void	error_exit(char *msg);

#endif