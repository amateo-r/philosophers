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

enum e_status
{
	DEAD = 0,
	LIVE = 1,
	DONE = 2
};

enum e_action
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2
};

/**
 * DESCRIPTION:
 * Class to store each philosopher's data. Represents a
 * philosopher.
 * PARAMETERS:
 * @param	pthread_t		tid		Current thread.
 * @param	int				status	DEAD 0, LIVE 1, DONE 2.
 * @param	int				action	THINKING 0, EATING 1, SLEEPING 2.
 * @param	int				foods	Times that a philosopher ate.
 * @param	struct timeval	birth	Date of born.
 */
typedef struct s_philosopher
{
	pthread_t		tid;
	int				id;
	int				status;
	int				action;
	int				foods;
	struct timeval	birth;
	struct s_phdata	*phdata;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
}	t_philosopher;

/**
 * DESCRIPTION:
 * Class to store general data that affects all
 * philosophers.
 * PARAMETERS:
 * @param	int				number_of_philos
 * @param	int				time_to_die
 * @param	int				time_to_eat
 * @param	int				time_to_sleep
 * @param	int				stop				If 1 simulation must stop.
 * @param	t_philosopher	*philo				Array of threads.
 */
typedef struct s_phdata
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				stop;
	t_philosopher	*philo;
}	t_phdata;

//	src/libft
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
float			ft_timediff(struct timeval start, struct timeval end);

//	src/exceptions_handlers.c
int				input_manager(int argc, char **argv);

//	src/init.c
void	init_data(int argc, char **argv, t_phdata *phdata);
void	init_philosophers(t_phdata *phdata);

//	src/philosophers_actions.c
void			*philosopher_manager(void *var);

//	src/forks.c
void			take_forks(t_philosopher *phil);
void			put_forks(void);
void			test_forks(void);

//	src/ft_print.c
void	ft_print(t_philosopher *philo, char *message);
void	ft_printst(t_philosopher *philo);

//	src/starter.c
void	hour_of_meet(t_philosopher *philo);

//	src/simultaion.c
void    simulation(t_phdata *phdata);

#endif
