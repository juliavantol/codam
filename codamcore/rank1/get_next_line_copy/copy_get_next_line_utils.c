/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:56:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/06 14:36:10 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str)
{
	size_t	index;

	index = 0;
	if (str[index] == '\n')
		return (&((char *) str)[index]);
	while (index < (ft_strlen(str) + 1))
	{
		if (str[index] == '\n')
			return (&((char *) str)[index + 1]);
		index++;
	}
	return (NULL);
}

int	search_newline(char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (index < ft_strlen(s))
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (0);
}

char	*ft_strjoin(char *stash, char *str, size_t index, size_t start)
{
	char	*new_str;

	if (!stash)
	{
		stash = ft_calloc(1, 1);
		if (stash == NULL)
			return (free(str), NULL);
	}
	new_str = malloc(sizeof(char) * ft_strlen(stash) + ft_strlen(str) + 1);
	if (!new_str)
		return (free(str), free(stash), NULL);
	while (stash[index])
	{
		new_str[index] = stash[index];
		index++;
	}
	while (str[start])
		new_str[index++] = str[start++];
	new_str[index] = '\0';
	free(stash);
	return (new_str);
}

char	*new_stash(char *str)
{
	char	*stash;
	size_t	i;
	size_t	index;

	stash = malloc(sizeof(char) * ft_strlen(str) + 1);
	index = search_newline(str) + 1;
	i = 0;
	while (str[index])
		stash[i++] = str[index++];
	stash[i] = '\0';
	free(str);
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	index;
	char	*line;

	index = 0;
	line = malloc(ft_strlen(stash) + 1);
	while (index < ft_strlen(stash))
	{
		line[index] = stash[index];
		if (stash[index] == '\n')
			break ;
		index++;
	}
	return (line);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void			*m;
	unsigned char	*p;
	size_t			index;

	m = malloc(nelem * elsize);
	if (m == NULL)
		return (NULL);
	p = m;
	index = 0;
	while (index < nelem * elsize)
	{
		p[index] = '\0';
		index++;
	}
	return (m);
}