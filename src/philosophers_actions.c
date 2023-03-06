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
	// struct timeval	end;

	// mutex lock &philo->phdata->dead
	if (philo->status != LIVE) // [DEV] || philo->phdata->stop)
		return (0);
	// mutex unlock &philo->phdata->dead
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
	if (philo->foods < philo->phdata->times_to_eat && philo->status == LIVE)
	{
		philo->action = EATING;
		ft_print(philo, "is eating");
		// lock fork_l [NOTE] Lock it in function take_fork
		// lock fork_r
		usleep(philo->phdata->time_to_eat);
		// unlock fork_l
		// unlock fork_r
		philo->foods++;
		if (philo->foods > philo->phdata->times_to_eat)
			philo->status = DONE;
		// gettimeofday(philo->birth, NULL);
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
	while(philo->foods < philo->phdata->times_to_eat && check_status(philo)) 
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	ft_printst(philo);
	return (NULL);
}
