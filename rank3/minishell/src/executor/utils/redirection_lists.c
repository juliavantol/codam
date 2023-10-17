/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirection_lists.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/15 16:11:40 by Julia         #+#    #+#                 */
/*   Updated: 2023/10/17 15:17:18 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

t_filenames	*last_node(t_filenames *filename)
{
	t_filenames	*temp;

	temp = filename;
	if (filename != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	return (temp);
}

t_filenames	*new_node(char *name, int mode)
{
	t_filenames	*node;

	node = malloc(sizeof(t_filenames));
	if (node == NULL)
		return (NULL);
	if (name == NULL)
		node->filename = NULL;
	else
		node->filename = ft_strdup(name);
	node->mode = mode;
	node->next = NULL;
	return (node);
}

void	add_node(t_filenames **filenames, char *name, int mode)
{
	t_filenames	*last;
	t_filenames	*new;

	new = new_node(name, mode);
	if (*filenames != NULL && new != NULL)
	{
		last = last_node(*filenames);
		last->next = new;
	}
	else
		*filenames = new;
}
