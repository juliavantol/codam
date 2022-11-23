/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:56:18 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/21 16:56:40 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_str(char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		write(1, &s[index], 1);
		index++;
	}
}