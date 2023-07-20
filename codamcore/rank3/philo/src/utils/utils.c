/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 11:55:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/07/20 23:21:59 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_ms(void)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time);
}

int valid_input(t_data philo)
{
	if (philo.number_of_times_to_eat == 1)
	{
		if (philo.max_meals < 1)
			return (-1);
	}
	if (philo.number_of_philosophers < 1 || philo.time_to_die < 1
		|| philo.time_to_eat < 1)
		return (-1);
	return (0);
}

int check_input(int argc)
{
	if (argc != 5 && argc != 6)
	{
		put_str("Invalid number of arguments\n", 2);
		return (-1);
	}
	return (0);
}
