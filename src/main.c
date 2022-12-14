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
 * Initialize philosophers data.
 * PARAMETERS:
 * @param	int	number_of_phislophers	Input cont of philosophers and forks.
 */
t_philosopher	*init_philosophers(int number_of_philosophers)
{
	t_philosopher	*tinfo;
	int				i;

	tinfo = calloc(number_of_philosophers, sizeof(*tinfo)); // función prohibida
	i = -1;
	while (++i < number_of_philosophers)
	{
		tinfo[i].id = i;
		tinfo[i].state = THINKING;
		// Right fork
		// Left fork
		continue ;
	}
	return (tinfo);
}
// #define LEFT (i + N - 1) % N
// #define RIGHT (i + 1) % N 

/**
 * DESCRIPTION:
 * Returns the difference from a time interval.
 * PARAMETERS:
 * @param	struct timeval	start	First time register.
 * @param	struct timeval	end		Last time register.
 */
float	ft_timediff(struct timeval start, struct timeval end)
{
	return ((end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec));
}

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
	t_philosopher	*tinfo;
	int				number_of_philosophers;
	int				i;
	// struct timeval	start, end;

	// i = gettimeofday(&start, NULL);
	// usleep(3000000);
	// i = gettimeofday(&end, NULL);
	// if (!i)
	// 	printf("\tEnd:\n%lf segundos\n", ft_timediff(start, end));
	tinfo = NULL;
	if (!input_manager(argc, argv))
	{
		printf("Iniciando...\n");
		number_of_philosophers = ft_atoi(argv[1]);
		tinfo = init_philosophers(number_of_philosophers);
		i = -1;
		// [NOTE] Aquí tendría que existir un gettimeofday probablemente para guardar el inicio de la simulación.
		while (++i < number_of_philosophers)
			pthread_create(&tinfo[i].tid, NULL, philosopher_manager, &tinfo[i]);
		// for (int j = 0; j < number_of_philosophers; j++)
		// 	printf("\nState [%d] in main: %d\n", tinfo[j].id, tinfo[j].state);
		i = -1;
		while (++i < number_of_philosophers)
			pthread_join(tinfo[i].tid, NULL); // [NOTE] Comprobar el tipo de dato que devuelve esto y los errores que puedan ocurrir.
		//pthread_exit(NULL); // No está permitida.
	}
	return (0);
}
