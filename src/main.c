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
 * @param	int		argcc	Number of inputs.
 * @param	char	**argv	Input paramters.
 */
t_philosopher	*init_philosophers(int argc, char **argv)
{
	t_philosopher	*tinfo;
	int				i;
	int				number_of_philosophers;

	number_of_philosophers = ft_atoi(argv[1]);
	tinfo = calloc(number_of_philosophers, sizeof(*tinfo)); // función prohibida
	i = -1;
	while (++i < number_of_philosophers)
	{
		tinfo[i].id = i;
		tinfo[i].state = THINKING;
		if (argc == 4)
			tinfo[i].times_to_eat = ft_atoi(argv[5]);
		// Right fork
		// Left fork
	}
	return (tinfo);
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
	if (!input_manager(argc - 1, argv))
	{
		printf("Iniciando...\n");
		number_of_philosophers = ft_atoi(argv[1]);
		tinfo = init_philosophers(argc, argv);
		i = -1;
		// [NOTE] Aquí tendría que existir un gettimeofday probablemente para guardar el inicio de la simulación.
		while (++i < number_of_philosophers)
			pthread_create(&tinfo[i].tid, NULL, philosopher_manager, &tinfo[i]);
		i = -1;
		while (++i < number_of_philosophers)
			pthread_join(tinfo[i].tid, NULL); // [NOTE] Comprobar el tipo de dato que devuelve esto y los errores que puedan ocurrir.
	}
	return (0);
}
