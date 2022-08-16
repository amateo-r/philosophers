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

# define THINKING 0
# define EATING 1
# define SLEEPING 2

/**
 * DESCRIPTION:
 * Class to store philosopher's data. Represents a
 * philosopher.
 * PARAMETERS:
 * @param	int			state		THINKING 0, EATING 1, SLEEPING 2.
 * @param	pthread_t	thread_id	Current thread.
 */
typedef struct s_philosopher
{
	pthread_t	thread_id;
	int			id;
	int			state;
	// ID tenedor derecho
	// ID tenedor izquierdo
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
void	sleeping(void) // ¿Personalizado?¿Sincronización?
void	philosopher_manager(void); // Debe sustituirse el argumento vacío por t_philosopher.

#endif
