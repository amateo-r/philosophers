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
// int	init_mutex(t_data *data, int argc);

/**
 * DESCRIPTION:
 * Input data stored.
 * PARAMETERS:
 * @param	int				argc	Number of inputs.
 * @param	char			**argv	Input paramters.
 * @param	t_phdata		*phdata	philosopher general data.
 */
void	init_data(int argc, char **argv, t_phdata *phdata)
{
	phdata->number_of_philos = ft_atoi(argv[1]);
	phdata->time_to_die = ft_atoi(argv[2]);
	phdata->time_to_eat = ft_atoi(argv[3]);
	phdata->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 4)
		phdata->times_to_eat = ft_atoi(argv[5]);
	else
		phdata->times_to_eat = 1;
	phdata->mutex = NULL; // init_mutex
	return ;
}

/**
 * DESCRIPTION:
 * Initialize philosophers data.
 * PARAMETERS:
 * @param	char	**argv	Input paramters.
 */
t_philosopher	*init_philosophers(char **argv)
{
	t_philosopher	*philo;
	int				i;
	int				number_of_philosophers;
	struct timeval	start;

	number_of_philosophers = ft_atoi(argv[1]);
	philo = calloc(number_of_philosophers, sizeof(*philo));		// [NOTE] función prohibida
	i = -1;
	gettimeofday(&start, NULL);									// Registro oficial del inicio de la simulación.
	while (++i < number_of_philosophers)
	{
		philo[i].id = i;
		philo[i].state = THINKING;
		philo[i].birth = start;
	}
	return (philo);
}
