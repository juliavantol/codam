/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routines.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/18 12:28:48 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/21 14:53:50 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Keeps checking if a philosopher should be dead */
void	*death_patrol(void *args)
{
	t_philosopher	*philo;
	u_int64_t		current_time;

	philo = (t_philosopher *)args;
	while (is_dead(philo->data) == false)
	{
		current_time = get_time_ms() - philo->data->start_time;
		pthread_mutex_lock(&philo->lock);
		if (current_time > philo->last_meal + philo->data->die_time)
		{
			pthread_mutex_unlock(&philo->lock);
			message(philo->data, DEAD, philo->id);
		}
		else
			pthread_mutex_unlock(&philo->lock);
		usleep(1000);
	}
	return (0);
}

/* Keep eating and sleeping until max meals have been eaten
or until someone has died */
void	*philo_routine(void *args)
{
	t_philosopher	*philo;
	pthread_t		t;

	philo = (t_philosopher *)args;
	if (pthread_create(&t, NULL, &death_patrol, (void *)philo) != 0)
		return (0);
	if (philo->id % 2 != 0 && philo->data->philo_count != 1)
		ft_usleep(philo->data, philo->data->eat_time);
	while (is_dead(philo->data) == false)
	{
		if (eat_meal(philo) == -1)
		{
			if (pthread_join(t, NULL) != 0)
				return (0);
			return (0);
		}
	}
	if (pthread_join(t, NULL) != 0)
		return (0);
	return (0);
}
