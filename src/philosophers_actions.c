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

int		check_status(t_philosopher *philo)
{
	struct timeval	end;

	if (philo->status != LIVE || philo->phdata->stop)
		return (0);
	gettimeofday(&end, NULL);
	if (ft_timediff(philo->birth, end) * 1e6 > philo->phdata->time_to_die)
	{
		printf("\tPara philo %d han pasado %lf segundos desde su nacimiento\n", philo->id, ft_timediff(philo->birth, end));
		pthread_mutex_lock(philo->mutex);
		philo->status = DEAD;
		return(0);
	}
	if ((ft_timediff(philo->birth, end) * 1e6 - philo->phdata->time_to_die) < philo->phdata->time_to_eat)
	{
		printf("\tPara philo %d han pasado %lf segundos desde su nacimiento\n", philo->id, ft_timediff(philo->birth, end));
		pthread_mutex_lock(philo->mutex);
		philo->status = DEAD;
		return(0);
	}
	return (1);
}

void	thinking(t_philosopher *philo)
{
	philo->action = THINKING;
	ft_print(philo, "is thinking");
	usleep(philo->phdata->time_to_eat);
	return ;
}

void	eating(t_philosopher *philo)
{
	if (philo->times_to_eat > 0 && philo->status == LIVE)
	{
		pthread_mutex_lock(philo->mutex);
		philo->action = EATING;
		ft_print(philo, "is eating");
		// close mutex
		// bloquear tenedor derecho
		// bloquear tenedor izquierdo
		usleep(philo->phdata->time_to_eat);
		// liberar tenedor derecho
		// liberar tenedor izquierdo
		// open mutex
		philo->times_to_eat--;
		if (philo->times_to_eat == 0)
			philo->status = DONE;
		// gettimeofday(philo->birth, NULL);
		pthread_mutex_unlock(philo->mutex);
	}
	return ;
}

void	sleeping(t_philosopher *philo)
{
	philo->action = SLEEPING;
	ft_print(philo, "is sleeping");
	usleep(philo->phdata->time_to_sleep );
	return ;
}

void	*philosopher_manager(void *var)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) var;
	if (philo->id % 2 == 0)
		thinking(philo);
	while(philo->times_to_eat > 0 && check_status(philo)) 
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	ft_printst(philo);
	return (NULL);
}


// if (self->id % 2 == 0)
// {
// 	ft_print (self, "is thinking");
// 	ft_msleep (self->data->time_eat);
// }
// while (1)
// {
// 	if (ft_check_died(self))
// 		break ;
// 	if (ft_eating (self) != SUCCESS)
// 		break ;
// 	ft_print (self, "is thinking");
// 	ft_msleep (self->data->time_thk);
// }
