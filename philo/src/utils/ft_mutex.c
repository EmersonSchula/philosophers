/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:20:17 by eschula           #+#    #+#             */
/*   Updated: 2025/04/14 14:52:16 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mutex.h"

static	t_mutex	*get_mutex(void)
{
	static t_mutex	mutex;

	return (&mutex);
}

int	ft_mutex_init(pthread_mutex_t *mutex)
{
	t_mutex	*mtx;

	mtx = get_mutex();
	if (pthread_mutex_init(mutex, NULL))
		return (1);
	mtx->list[mtx->i] = mutex;
	mtx->i++;
	return (0);
}

void	ft_mutex_destroy_all(void)
{
	t_mutex	*mtx;

	mtx = get_mutex();
	while (mtx->i > 0)
	{
		mtx->i--;
		pthread_mutex_destroy(mtx->list[mtx->i]);
		mtx->list[mtx->i] = NULL;
	}
}

void	ft_mutex_lock(pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
}

void	ft_mutex_unlock(pthread_mutex_t *mutex)
{
	pthread_mutex_unlock(mutex);
}
