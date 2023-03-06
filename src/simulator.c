#include "../libphil.h"

void    simulation(t_phdata *phdata)
{
    int i;

    i = -1;
		while (++i < phdata->number_of_philos)
			pthread_create(&phdata->philo[i].tid, NULL, philosopher_manager, &(phdata->philo[i]));
		i = -1;
		while (++i < phdata->number_of_philos)
			pthread_join(phdata->philo[i].tid, NULL); // [DEV] Comprobar el tipo de dato que devuelve esto y los errores que puedan ocurrir.
    return ;
}