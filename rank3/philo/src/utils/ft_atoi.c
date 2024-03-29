/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 13:03:01 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/11 16:59:15 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	convert(const char *str, int index, int n)
{
	int	sum;

	sum = 0;
	while (ft_isdigit(str[index]))
		sum = sum * 10 + str[index++] - 48;
	return (sum * n);
}

static int	find_start(const char *str)
{
	int	start;
	int	n;

	start = 0;
	n = 1;
	while ((str[start] >= 9 && str[start] <= 13) || str[start] == ' ')
		start++;
	if (str[start] == '-' || str[start] == '+')
	{
		if (str[start] == '-')
			n = -1;
		start++;
	}
	return (convert(str, start, n));
}

int	ft_atoi(const char *str)
{
	int	index;

	index = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) > 10)
		return (-1);
	while (str[index])
	{
		if (ft_isdigit(str[index++]) == 0)
			return (-1);
	}
	if (str == NULL)
		return (ft_atoi(str));
	return (find_start(str));
}
