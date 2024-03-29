/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:18:23 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/03/23 14:07:32 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "includes/libft/libft.h"
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		outfile;
	int		infile;
	char	**paths;
	char	*cmd;
	char	**cmd_split;
	char	**full_envp;
}	t_pipex;

char	**ft_split_paths(char *whole_str);
char	**ft_split_args(char *s);
char	**manual_envp(void);
char	*get_cmd_path(char **paths, char	*cmd);
void	get_envp(t_pipex *pipex, char **envp);
void	free_cmd_split(t_pipex *pipex);
void	error_exit(char *msg);

#endif
