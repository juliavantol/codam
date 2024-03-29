/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Julia <Julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 16:29:29 by Julia         #+#    #+#                 */
/*   Updated: 2023/08/23 18:15:41 by juvan-to      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	p;

	if (parse_input(argc, argv, &data) == -1)
		return (ft_error(&data, "Error: invalid input\n", 0));
	data.start_time = get_time_ms();
	if (init_struct(&data, 0) == -1)
		return (ft_error(&data, "Error\n", 1));
	p = NULL;
	if (init_threads(&data, 0, p) == 0)
		ft_exit(&data, 6);
	return (0);
}
