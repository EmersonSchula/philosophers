/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:38:02 by eschula           #+#    #+#             */
/*   Updated: 2025/04/07 19:49:24 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "string.h"

static t_malloc	*get_malloc(void)
{
	static t_malloc	mlc;

	return (&mlc);
}

void	*ft_malloc(size_t size)
{
	t_malloc	*mlc;
	void		*ptr;

	mlc = get_malloc();
	ptr = malloc(size);
	memset(ptr, 0, size);
	mlc->list[mlc->i] = ptr;
	mlc->i++;
	return (ptr);	
}
