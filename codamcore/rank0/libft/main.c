/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:35:40 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/10/24 18:30:59 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	printf("%d\n", ft_atoi("120ahdh9"));
}

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	int		reverse;
// 	int		multi;

// 	str = "a";
// 	if (!str)
// 		return (NULL);
// 	reverse = 0;
// 	multi = 1;
// 	while (n >= 10)
// 	{
// 		reverse += ((n % 10) * multi);
// 		multi *= 10;
// 		n = n / 10;
// 	}
// 	reverse += ((n % 10) * multi);
// 	printf("%d\n", reverse);
// 	return (str);
// }
