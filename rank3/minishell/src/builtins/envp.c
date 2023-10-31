/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 13:54:40 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/01 00:29:23 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	init_envp(t_exe *executor, char **envp)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	i = 0;
	executor->envp_list = NULL;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		key = ft_substr(envp[i], 0, j);
		value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j);
		add_node_envp(&executor->envp_list, key, value);
		free(key);
		free(value);
		i++;
	}
	executor->paths = get_paths(envp);
}

void	print_env(t_exe *executor, t_cmd *command)
{
	t_envp	*head;

	if (executor->envp_list == NULL)
		return ;
	head = executor->envp_list;
	while (head != NULL)
	{
		printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
	(void)command;
}

void	prepare_export(t_exe *executor, t_cmd *command)
{
	char	**name;

	name = ft_split(command->command_name, ' ');
	export(executor, name[1], name[2]);
	empty_array(name);
}

void	prepare_unset(t_exe *executor, t_cmd *command)
{
	char	**name;

	name = ft_split(command->command_name, ' ');
	unset(executor, name[1]);
	empty_array(name);
}

void	export(t_exe *executor, char *key, char *value)
{
	t_envp	*head;

	head = executor->envp_list;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
		{
			free(head->value);
			head->value = ft_strdup(value);
			return ;
		}
		head = head->next;
	}
	add_node_envp(&executor->envp_list, key, value);
}

void	unset(t_exe *executor, char *key)
{
	t_envp	*head;
	t_envp	*prev;

	head = executor->envp_list;
	prev = NULL;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key))
		{
			if (prev == NULL)
				executor->envp_list = head->next;
			else
				prev->next = head->next;
			free(head->key);
			free(head->value);
			free(head);
			return ;
		}
		prev = head;
		head = head->next;
	}
}
