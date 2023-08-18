/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 12:17:54 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/08/07 14:48:42 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philosopher *philo, u_int64_t time)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (philo->data->dead != 0)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id, time);
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id, time);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[right]);
		message(philo->data, FORK, philo->id, time);
		pthread_mutex_lock(&philo->data->forks[left]);
		message(philo->data, FORK, philo->id, time);
	}
}

void	put_forks_down(t_philosopher *philo, u_int64_t time)
{
	int	left;
	int	right;

	left = philo->id - 1;
	right = philo->id % philo->data->philo_count;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[left]);
		pthread_mutex_unlock(&philo->data->forks[right]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[right]);
		pthread_mutex_unlock(&philo->data->forks[left]);
	}
	//pthread_mutex_lock(&philo->data->lock);
	if (philo->data->dead == 0)
	{
		message(philo->data, SLEEPING, philo->id, time);
		ft_usleep(philo->data, philo->data->sleep_time);
	}
	// pthread_mutex_unlock(&philo->data->lock);
}

void	eat_meal(t_philosopher *philo)
{
	u_int64_t	time;

	time = get_time_ms() - philo->data->start_time;
	take_forks(philo, time);
	time = get_time_ms() - philo->data->start_time;
	message(philo->data, EATING, philo->id, time);
	pthread_mutex_lock(&philo->lock);
	philo->last_active = get_time_ms() - philo->data->start_time;
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->data, philo->data->eat_time);
	time = get_time_ms() - philo->data->start_time;
	put_forks_down(philo, time);
	pthread_mutex_lock(&philo->lock);
	philo->meals += 1;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(&philo->data->lock);
	philo->data->total_meals += 1;
	pthread_mutex_unlock(&philo->data->lock);
}