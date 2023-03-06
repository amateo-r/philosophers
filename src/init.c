/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:18:03 by amateo-r          #+#    #+#             */
/*   Updated: 2023/02/27 10:18:05 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libphil.h"

/**
 * DESCRIPTION:
 * Birth of mutexes.
 * PARAMETERS:
 * 
 */
// int	init_mutex(t_philosopher *philo)
// {
// 	philo->mutex = malloc(sizeof(pthread_mutex_t));
// 	pthread_mutex_init(philo->mutex, NULL);
// 	if (!philo->mutex)
// 		return (0); // liberar memoria
// 	return (1);
// }

/**
 * DESCRIPTION:
 * Input data stored.
 * PARAMETERS:
 * @param	char			**argv	Input paramters.
 * @param	t_phdata		*phdata	philosopher general data.
 */
void	init_data(int argc, char **argv, t_phdata *phdata)
{
	phdata->number_of_philos = ft_atoi(argv[1]);
	phdata->time_to_die = ft_atoi(argv[2]) * 1e3;
	phdata->time_to_eat = ft_atoi(argv[3]) * 1e3;
	phdata->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	if (argc == 5)
		phdata->times_to_eat = ft_atoi(argv[5]);
	else
		phdata->times_to_eat = 1;
	phdata->stop = 0;
	phdata->philo = malloc(sizeof(t_philosopher) * phdata->number_of_philos);
	// Check philosopher memory allocation
	return ;
}

/**
 * DESCRIPTION:
 * Initialize each philosopher.
 * PARAMETERS:
 * @param	int			argc	Number of inputs.
 * @param	char		**argv	Input paramters.
 * @param	t_phdata	*phdata	General data about philosophers.
 */
void	init_philosophers(t_phdata *phdata)
{
	int				i;
	struct timeval	start;


	i = -1;
	gettimeofday(&start, NULL); // Registro oficial del inicio de la simulación.
	while (++i < phdata->number_of_philos)
	{
		phdata->philo[i].id = i + 1;
		phdata->philo[i].status = LIVE;
		phdata->philo[i].action = THINKING;
		phdata->philo[i].foods = 0;
		phdata->philo[i].birth = start;
		phdata->philo[i].phdata = phdata;
		pthread_mutex_init(&(phdata->philo[i].fork_l), NULL);
		// [DEV] Check memory alocation of mutex.
		if (i == phdata->number_of_philos - 1)
			phdata->philo[i].fork_r = &phdata->philo[0].fork_l;
		else
			phdata->philo[i].fork_r = &phdata->philo[i + 1].fork_l;
	}
	return ;
}
