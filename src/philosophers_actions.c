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

void	thinking(int time_to_think)
{
	usleep(time_to_think);
	return ;
}

void	eating(void)
{
	// close mutex
	// bloquear tenedor derecho
	// bloquear tenedor izquierdo
	// usleep(time_to_eat)
	// liberar tenedor derecho
	// liberar tenedor izquierdo
	// open mutex
	return ;
}

void	sleeping(void)
{
	//usleep(teme_to_sleep)
	return ;
}

void	*philosopher_manager(void *var)
{
	struct timeval	start;
	t_philosopher	*phil;

	phil = (t_philosopher *) var;
	printf("Thread [%d]: %d\n", (int) phil->id, (int) phil->tid);
	gettimeofday(&start, NULL); // [NOTE] Inicio del filósofo diría yo. ¿Comprobar en cada acción su vida? Esto consume tiempo.
	take_forks(phil);
	// while(1)
	// {
		// ¿eat or think?
		// take_forks
		// eating
		// put_forks
		// sleeping
		// thinking(phil->id);
	// }
	return (NULL);
}
