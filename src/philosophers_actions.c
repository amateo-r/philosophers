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

	// mutex lock &philo->phdata->dead
	if (philo->phdata->stop)
		return (0);
	if (philo->foods == 0 && philo->status == LIVE)
	{
		philo->status = DONE;
		philo->phdata->done_philos++;
		if (philo->phdata->done_philos == philo->phdata->number_of_philos)
			philo->phdata->stop = 1;
	}
	gettimeofday(&end, NULL);
	printf("Diferencia de %d: %f --- %f\n", philo->id, ft_timediff(philo->birth, end), philo->phdata->time_to_die);
	if (philo->status == LIVE && ft_timediff(philo->birth, end) >= philo->phdata->time_to_die)
	{
		philo->status = DEAD;
		philo->phdata->stop = 1;
	}
	if (philo->status != LIVE || philo->phdata->stop) // [DEV] || philo->phdata->stop)
		return (0);
	// mutex unlock &philo->phdata->dead
	return (1);
}

void	thinking(t_philosopher *philo)
{
		philo->action = THINKING;
		if (!philo->phdata->stop)
			ft_print(philo, "is thinking");
		usleep(philo->phdata->time_to_eat);
	return ;
}

void	eating(t_philosopher *philo)
{
	struct timeval	end;

	if (philo->foods <= philo->phdata->times_to_eat)
	{
		philo->action = EATING;
		ft_print(philo, "is eating");
		pthread_mutex_lock(&philo->fork_l);		// lock fork_l [NOTE] Lock it in function take_fork
		pthread_mutex_lock(philo->fork_r); 		// lock fork_r
		usleep(philo->phdata->time_to_eat);
		pthread_mutex_unlock(&philo->fork_l);	// unlock fork_l
		pthread_mutex_unlock(philo->fork_r);	// unlock fork_r
		gettimeofday(&end, NULL);
		if (check_status(philo))
			return ;
		else
		{
			philo->foods--;
			if (philo->foods <= 0)
				philo->status = DONE;
		}
		// gettimeofday(&philo->birth, NULL);
	}
	return ;
}

void	sleeping(t_philosopher *philo)
{
		philo->action = SLEEPING;
		if (!philo->phdata->stop)
			ft_print(philo, "is sleeping");
		usleep(philo->phdata->time_to_sleep );
	return ;
}

void	*philosopher_manager(void *var)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) var;
	if (philo->id % 2 != 0)
		thinking(philo);
	while(check_status(philo))
	{
		if (philo->status == LIVE)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	ft_printst(philo);
	return (NULL);
}
