/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:09:07 by amateo-r          #+#    #+#             */
/*   Updated: 2022/08/11 12:09:09 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libphil.h"

/**
 * DESCRIPTION:
 * Los inputs son en orden:
 * 	- number_of_philosophers and forks.
 * 	- time_to_die.
 * 	- time_to_eat.
 * 	- time_to_sleep.
 * 	- number_of_times_each_philospher_must_eat. [OPTIONAL]
 */
int	main(int argc, char **argv)
{
	t_phdata		phdata;
	// struct timeval	start;
	// struct timeval	end;

	// i = gettimeofday(&start, NULL);
	// usleep(3000000);
	// i = gettimeofday(&end, NULL);
	// if (!i)
	// 	printf("\tEnd:\n%lf segundos\n", ft_timediff(start, end));
	if (!input_manager(argc - 1, argv))
	{
		printf("Iniciando...\n");
		init_data(argc - 1, argv, &phdata);
		init_philosophers(&phdata);
		simulation(&phdata);
		free(phdata.philo);
	}
	return (0);
}
