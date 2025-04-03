/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:21:45 by eschula           #+#    #+#             */
/*   Updated: 2025/03/19 15:15:17 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	handle_error(int error_code)
{
	if (error_code == E_FEW_ARGS)
		printf("Error: Too few arguments\n");
	if (error_code == E_MANY_ARGS)
		printf("Error: Too many arguments\n");
	if (error_code == E_INVALID_ARG)
		printf("Error: Invalid argument\n");
	if (error_code == E_INVALID_PHIL_NUM)
		printf("Error: Invalid number of philosophers\n");
	
	return (true);
}