/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:40:27 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/12/08 14:33:02 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	// char		*line;
	int			check;

	if (!fd || BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	check = read(fd, buffer, BUFFER_SIZE);
	while (check > 0)
	{
		buffer[check] = '\0';
		stash = ft_strjoin(stash, buffer, 0, 0);
		if (!stash)
			return (NULL);
		check = read(fd, buffer, BUFFER_SIZE);
	}
	// if (ft_strchr(stash) != NULL)
	// {
	// 	line = extract_line(stash);
	// 	stash = new_stash(stash);
	// 	return (free(buffer), line);
	// }
	free(buffer);
	return (0);
}
