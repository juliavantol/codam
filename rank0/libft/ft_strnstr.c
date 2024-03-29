/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:08:46 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/31 16:11:03 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locates the first occurrence of the needle in the haystack. No more than 
len characters are searched. If needle is an empty, haystack is returned; 
if needle is not in haystack, NULL is returned.  Otherwise a pointer to the 
first character of the first occurrence of needle is returned */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	char	*sub;

	i = 0;
	sub = "a";
	if ((haystack == NULL || haystack[0] == '\0')
		&& ft_strncmp(haystack, needle, ft_strlen(needle)) != 0)
		return (NULL);
	if (needle[0] == '\0' || ft_strlen(needle) <= 0 || ft_strlen(haystack) == 0)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (i < ft_strlen(haystack) && i < len && (i + n_len - 1) < len)
	{
		sub = ft_substr(haystack, i, n_len);
		if (ft_strncmp(sub, needle, n_len) == 0)
		{
			free(sub);
			return ((char *)&haystack[i]);
		}
		free(sub);
		i++;
	}
	return (NULL);
}
