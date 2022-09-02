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
	SLEEPING = 2,
	HUNGRY = 3
};

/**
 * DESCRIPTION:
 * Class to store philosopher's data. Represents a
 * philosopher.
 * PARAMETERS:
 * @param	pthread_t	tid		Current thread.
 * @param	int			state	THINKING 0, EATING 1, SLEEPING 2.
 */
typedef struct s_philosopher
{
	pthread_t	tid;
	int			id;
	int			state;
}	t_philosopher;

//	src/libft
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);

//	src/exceptions_handlers.c
int		input_manager(int argc, char **argv);

//	init_philosophers

//	src/philosophers_actions.cs
void	thinking(void);
void	eating(void);
void	sleeping(void);
void	*philosopher_manager(void *var);

//	src/forks.c
void	take_forks(t_philosopher *phil);
void	put_forks(void);
void	test_forks(void);

#endif
