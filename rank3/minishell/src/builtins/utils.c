/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/15 02:06:06 by Julia         #+#    #+#                 */
/*   Updated: 2023/09/15 13:11:17 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*join_three_strs(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;
	char	*output;

	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	output = ft_malloc(sizeof(char) * (i + 1));
	j = 0;
	j--;
	return (output);
}