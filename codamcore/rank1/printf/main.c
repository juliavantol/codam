/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:46:04 by juvan-to      #+#    #+#                 */
/*   Updated: 2022/11/13 00:17:26 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		a;
	int		b;
	void	*p;
	void	*p2;

	a = -2147483647 - 1;
	p = &a;
	b = 2147483647;
	p2 = &b;

	printf("\n%d\n", printf(" %p %p ", p, p2));
	printf("\n%d\n", ft_printf(" %p %p ", p, p2));
	return (0);
}