/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:21:45 by eschula           #+#    #+#             */
/*   Updated: 2025/04/14 15:11:00 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	clear_all(char *error)
{
	ft_mutex_destroy_all();
	ft_free_all();
	write(2, error, ft_strlen(error));
}

static void	print_guide(void)
{
	const char	*usage_guide = "\n"C_CYA C_BLD"Usage:"C_RST C_WHT"./philo"C_RST
		C_CYA C_BLD "[" C_RST "number_of_philosophers" C_CYA C_BLD "] " C_RST
		C_CYA C_BLD "[" C_RST "time_to_die" C_CYA C_BLD "]\n" C_RST
		"\t\t" C_CYA C_BLD "[" C_RST "time_to_eat" C_CYA C_BLD "] " C_RST
		C_CYA C_BLD "[" C_RST "time_to_sleep" C_CYA C_BLD "]\n" C_RST
		"\t\t" C_CYA C_BLD "[" C_RST "times_each_philosophers_must_eat"
		C_CYA C_BLD "[ " C_RST "(optional)\n\n";

	write(2, usage_guide, ft_strlen(usage_guide));
}

void	print_error(char *error)
{
	write(2, C_RED, ft_strlen(C_RED));
	write(2, error, ft_strlen(error));
	write(2, C_RST, ft_strlen(C_RST));
	print_guide();
}

static void	exit_succes(void)
{
	size_t		i;
	pthread_t	thread;

	i = 0;
	while (i < get_rules()->num_of_philosophers)
	{
		thread = get_rules()->philo[i].thread.thread;
		if (pthread_join(thread, NULL))
			perror("pthread_join");
		i++;
	}
	ft_mutex_destroy_all();
	ft_free_all();
}

t_bool	handle_error(t_error error)
{
	if (error == E_SUCCESS)
		exit_succes();
	if (error == E_FEW_ARGS)
		print_error("Error: Too few arguments\n");
	if (error == E_MANY_ARGS)
		print_error("Error: Too many arguments\n");
	if (error == E_INVALID_ARGS)
		print_error("Error: Invalid argument\n");
	if (error == E_INVALID_PHIL_NUM)
		print_error("Error: Invalid number of philosophers\n");
	if (error == E_MUTEX_FAILED)
		clear_all("thread failed!\n");
	if (error == E_THREAD_FAILED)
		clear_all("Thread failed !\n");
	return (true);
}
