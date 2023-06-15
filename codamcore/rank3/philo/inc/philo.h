/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:31:47 by Julia         #+#    #+#                 */
/*   Updated: 2023/06/15 17:41:23 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>

# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DEAD 4

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
	bool			available;
}	t_fork;

typedef struct s_philosopher
{
	int		state;
	t_fork	*fork_left;
	t_fork	*fork_right;
}	t_philosopher;

typedef struct s_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_to_eat;
	int				timestamp_ms;
	t_philosopher	*philosophers;
	t_fork			*all_forks;
}	t_philo;

void	timestamp_in_ms(t_philo philo);
void	parse_structs(t_philo *philo);
void	link_forks(t_philo *philo);
void	make_forks(t_philo *philo);
void	show_philos(t_philo philo);
void	put_str(char *str, int fd);
void	ft_putnum(int n);
void	put_char(char c);
int		ft_atoi(char *input);
int		ft_strlen(char *str);

#endif
