/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:09:12 by amateo-r          #+#    #+#             */
/*   Updated: 2022/08/16 13:09:15 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libphil.h"

void	thinking(void)
{

	return ;
}

void	eating(void)
{
	return ;
}

void	sleeping(void)
{
	return ;
}

void	*philosopher_manager(void *var)
{
	static int		a;
	t_philosopher	*phil;

	phil = (t_philosopher *) var;
	a = a + 11;
	printf("Thread [%d]: %d\n", (int) phil->id, a);

	take_forks(phil);
	// while(1)
	// {
		// thinking(phil->id);
		// take_forks
		// eating
		// put_forks
		// think(phil->id);
		// sleeping
	// }
	return (NULL);
}
