/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timediff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:58:57 by amateo-r          #+#    #+#             */
/*   Updated: 2023/01/20 10:58:58 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libphil.h"

/**
 * DESCRIPTION:
 * Returns the difference from a time interval in seconds.
 * PARAMETERS:
 * @param	struct timeval	start	First time register.
 * @param	struct timeval	end		Last time register.
 */
float	ft_timediff(struct timeval start, struct timeval end)
{
	return ((end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_usec - start.tv_usec));
}
