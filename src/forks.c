/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:28:28 by amateo-r          #+#    #+#             */
/*   Updated: 2022/09/02 10:28:30 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libphil.h"

void	test_forks(void)
{
	return ;
}
void	take_forks(t_philosopher *phil)
{
	phil->state = HUNGRY;
	printf("\tState: %d\n", phil->state);
	// test_forks
	return ;
}
void	put_forks(void);

