/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphil.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:18:49 by amateo-r          #+#    #+#             */
/*   Updated: 2022/08/11 12:18:50 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHIL_H
# define LIBPHIL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

enum e_state
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2
};

//	CREAR ESTRUCTURA args DONDE SE ALMACENE:
/**
 * DESCRIPTION:
 * Class to store general data that affects all
 * philosophers.
 * Tiempos para dormir, comer y morir
 * tid
 * mutex
 * thread states.
 * PARAMETERS:
 * @param	int	number_of_philos
 * @param	int	time_to_die
 * @param	int	time_to_eat
 * @param	int	time_to_sleep
 * @param	int	times_to_eat
 */
typedef struct s_phdata
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	pthread_mutex_t	*mutex;
} t_phdata;

/**
 * DESCRIPTION:
 * Class to store philosopher's data. Represents a
 * philosopher.
 * PARAMETERS:
 * @param	pthread_t		tid				Current thread.
 * @param	int				state			THINKING 0, EATING 1, SLEEPING 2.
 * @param	int				times_to_eat	Times that a philosopher must eat.
 * @param	struct timeval	birth			Date of born.
 */
typedef struct s_philosopher
{
	pthread_t		tid;
	int				id;
	int				state;
	int				times_to_eat;
	struct timeval	birth;
	t_phdata		*phdata;
}	t_philosopher;

//	src/libft
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
float			ft_timediff(struct timeval start, struct timeval end);

//	src/exceptions_handlers.c
int				input_manager(int argc, char **argv);

//	src/init.c
void			init_data(int argc, char **argv, t_phdata *phdata);
t_philosopher	*init_philosophers(char **argv);

//	src/philosophers_actions.c
void			thinking(t_philosopher *phil, int time_to_think);
void			eating(t_philosopher *phil, int time_to_eat);
void			sleeping(t_philosopher *phil, int time_to_sleep);
void			*philosopher_manager(void *var);

//	src/forks.c
void			take_forks(t_philosopher *phil);
void			put_forks(void);
void			test_forks(void);

#endif
