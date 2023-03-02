/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:09:12 by amateo-r          #+#    #+#             */
/*   Updated: 2022/08/16 13:09:15 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libphil.h"

void	ft_print(t_philosopher *philo, char *message)
{
	printf("%d %s\n", philo->id, message);
	return ;
}
