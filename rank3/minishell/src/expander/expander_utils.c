/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 23:28:32 by Julia         #+#    #+#                 */
/*   Updated: 2023/11/22 17:34:59 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*join_expanded_str(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;
	char	*output;

	i = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	output = ft_malloc(sizeof(char) * (i + 2));
	i = 0;
	j = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j])
		output[i++] = s2[j++];
	j = 0;
	while (s3[j])
		output[i++] = s3[j++];
	output[i] = '\0';
	return (output);
}

char	*find_variable_name(char *str, int index)
{
	char	*key;
	int		start;
	int		len;

	start = index;
	len = 0;
	while (str[index] && str[index] != ' ' && str[index] != '\0'
		&& str[index] != '"')
	{
		len++;
		index++;
	}
	key = ft_substr(str, start, len);
	return (key);
}

int	needs_expansion(char *str, int index)
{
	int		start_position;
	bool	in_single_quotes;

	start_position = 0;
	in_single_quotes = false;
	while (str[index])
	{
		if (str[index] == '\'')
			in_single_quotes = !in_single_quotes;
		else if (str[index] == '$' && !in_single_quotes)
		{
			start_position = index + 1;
			break ;
		}
		index++;
	}
	if (start_position == 0 || str[start_position] == '\0')
		return (0);
	return (start_position);
}

char	*remove_quotes(char *str, char quote, int i, int j)
{
	int	k;

	while (str[i])
	{
		if (str[i] == quote)
		{
			j = i;
			k = i;
			while (str[j] == quote)
				j++;
			while (str[j])
			{
				str[k] = str[j];
				k++;
				j++;
			}
			str[k] = '\0';
		}
		else
			i++;
	}
	return (str);
}