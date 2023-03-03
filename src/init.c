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
int	init_mutex(t_philosopher *philo)
{
	philo->mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->mutex, NULL);
	if (!philo->mutex)
		return (0); // liberar memoria
	return (1);
}

/**
 * DESCRIPTION:
 * Input data stored.
 * PARAMETERS:
 * @param	char			**argv	Input paramters.
 * @param	t_phdata		*phdata	philosopher general data.
 */
void	init_data(char **argv, t_phdata *phdata)
{
	phdata = (t_phdata *)malloc(sizeof(t_phdata) * 5);
	phdata->number_of_philos = ft_atoi(argv[1]);
	phdata->time_to_die = ft_atoi(argv[2]) * 1e3;
	phdata->time_to_eat = ft_atoi(argv[3]) * 1e3;
	phdata->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	phdata->stop = 0;
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
t_philosopher	*init_philosophers(int argc, char **argv, t_phdata *phdata)
{
	t_philosopher	*philo;
	int				i;
	struct timeval	start;

	philo = (t_philosopher *)malloc((sizeof(t_philosopher) + sizeof(t_phdata) * 5)* phdata->number_of_philos);
	i = -1;
	gettimeofday(&start, NULL); // Registro oficial del inicio de la simulación.
	start.tv_sec += 3;
	while (++i < phdata->number_of_philos)
	{
		philo[i].id = i;
		philo[i].status = LIVE;
		philo[i].action = THINKING;
		if (argc == 4)
			philo[i].times_to_eat = ft_atoi(argv[5]);
		else
			philo[i].times_to_eat = 1;
		philo[i].birth = start;
		philo[i].phdata = phdata;
		if (!init_mutex(&philo[i]))
		{
			printf("Error al inicializar mutex.\n");
			philo[i].mutex = NULL;
		}
	}
	return (philo);
}
