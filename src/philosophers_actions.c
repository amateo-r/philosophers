/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:09:12 by amateo-r          #+#    #+#             */
/*   Updated: 2022/08/16 13:09:15 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libphil.h"

void	thinking(t_philosopher *phil, int time_to_think)
{
	phil->state = THINKING;
	usleep(time_to_think);
	return ;
}

void	eating(t_philosopher *phil, int time_to_eat)
{
	phil->state = EATING;
	// close mutex
	// bloquear tenedor derecho
	// bloquear tenedor izquierdo
	usleep(time_to_eat);
	// liberar tenedor derecho
	// liberar tenedor izquierdo
	// open mutex
	phil->times_to_eat--;

	// put_forks
	return ;
}

void	sleeping(t_philosopher *phil, int time_to_sleep)
{
	phil->state = SLEEPING;
	usleep(time_to_sleep);
	return ;
}

void	*philosopher_manager(void *var)
{
	t_philosopher	*phil;

	phil = (t_philosopher *) var;
	printf("Thread [%d]: %d\n", (int) phil->id, (int) phil->tid);
	take_forks(phil);
	// while(phil->times_to_eat > 0) // [NOTE] Todo el mundo emplea 1 para crear un bucle eterno.
	// {
		// ¿eat or think?
		// take_forks
		// eating [put_forks inside]
		// sleeping
		// thinking(phil->id);
	// }
	return (NULL);
}
