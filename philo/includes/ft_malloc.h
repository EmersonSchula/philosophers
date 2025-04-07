/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:40:05 by eschula           #+#    #+#             */
/*   Updated: 2025/04/07 19:43:45 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>

typedef struct s_malloc
{
	void	*list[1000];
	size_t	i;
}			t_malloc;

void	*ft_malloc(size_t size);
void	ft_free_all(void);

#endif