/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:09:12 by amateo-r          #+#    #+#             */
/*   Updated: 2022/08/16 13:09:15 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libphil.h"

void	ft_print(t_philosopher *philo, char *message)
{
	printf("%d %s\n", philo->id, message);
	return ;
}

/**
 * DESCRIPTION:
 * Print status of a philosopher.
 */
void	ft_printst(t_philosopher *philo)
{
	if (philo->status == DEAD)
		ft_print(philo, "is DEAD");
	else if (philo->status == LIVE)
		ft_print(philo, "is LIVE");
	else if (philo->status == DONE)
		ft_print(philo, "is DONE");
	return ;
}
