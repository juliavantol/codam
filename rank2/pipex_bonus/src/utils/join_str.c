/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join_str.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 13:13:35 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/09/07 02:11:35 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_str2(char const *s1, char const *s2)
{
	size_t	str_len;
	char	*new_str;
	int		index;
	int		second;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		new_str[index] = s1[index];
		index++;
	}
	second = index;
	index = 0;
	while (s2[index] != '\0')
		new_str[second++] = s2[index++];
	new_str[second] = '\0';
	return (new_str);
}

char	*join_str(char const *s1, char const *s2)
{
	char	*output;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	output = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!output)
		error_exit("Malloc error");
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
