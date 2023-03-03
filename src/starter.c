/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:36:03 by amateo-r          #+#    #+#             */
/*   Updated: 2023/03/03 12:36:08 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libphil.h"

void	hour_of_meet(t_philosopher *philo)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	while(current.tv_sec < philo->birth.tv_sec)
		continue ;
	return ;
}
