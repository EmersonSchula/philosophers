/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:20:56 by eschula           #+#    #+#             */
/*   Updated: 2025/04/14 14:45:39 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUTEX_H
# define FT_MUTEX_H

# include <pthread.h>
# include <stdlib.h>

typedef struct s_mutex
{
	pthread_mutex_t	*list[1000];
	size_t			i;
}					t_mutex;

void				ft_mutex_destroy_all(void);
int					ft_mutex_init(pthread_mutex_t *mutex);
void				ft_mutex_lock(pthread_mutex_t *mutex);
void				ft_mutex_unlock(pthread_mutex_t *mutex);

#endif