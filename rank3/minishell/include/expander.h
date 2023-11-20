/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/19 13:31:33 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/11/20 00:25:41 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"
# include "builtins.h"

void	expand_command(t_exe *executor, t_cmd *command);

char	*get_variable(t_exe *executor, char *key);

#endif
