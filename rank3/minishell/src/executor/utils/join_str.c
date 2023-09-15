/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 13:13:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/15 16:03:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*join_str(char const *s1, char const *s2)
{
	char	*output;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	output = ft_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		output[i++] = s2[j++];
	output[i] = '\0';
	return (output);
}
