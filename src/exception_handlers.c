/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:18:08 by amateo-r          #+#    #+#             */
/*   Updated: 2022/08/11 12:18:11 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libphil.h"

/**
 * DESCRIPTION:
 * Checks that input number are positives.
 * RETURN:
 * If there is one negative number returns 0 else 1.
 * PARAMETERS:
 * @param	char	**argv	Input parameters from main.
 */
int	chk_negative(char **argv)
{
	int	flag;
	int	i;

	flag = 1;
	i = 0;
	while (argv[++i] && flag)
	{
		if (ft_atoi(argv[i]) < 0)
			flag = 0;
	}
	return (flag);
}

/**
 * DESCRIPTION:
 * Checks that input numbers aren't zero.
 * RETURN:
 * If there is one zero return 1 else 0.
 * PARAMETERS:
 * @param	char	**argv	Input parameters from main.
 */
int	chk_zero(char **argv)
{
	int	flag;
	int	i;

	flag = 1;
	i = 0;
	while (argv[++i] && flag)
	{
		if (ft_strncmp(argv[i], "0", 1) == 0)
			flag = 0;
	}
	return (flag);
}

/**
 * DESCRIPTION:
 * Checks that all inputs are intengers.
 * RETURN:
 * If there is a no integer return 0 else
 * return 1.
 * PARAMETERS:
 * @param	char	**argv	Input parameters from main.
 */
int	chk_integer(char **argv)
{
	int	flag;
	int	i;

	flag = 1;
	i = 0;
	while (argv[++i] && flag)
	{
		if (ft_strlen(argv[i]) == 11 && ft_strncmp(argv[i], \
			"-2147483648", 11) > 0)
			flag = 0;
		else if (ft_strlen(argv[i]) > 11)
			flag = 0;
		else if (ft_strlen(argv[i]) == 10 && ft_strncmp(argv[i], \
			"2147483647", 10) > 0)
			flag = 0;
		else if (ft_atoi(argv[i]) == -1 && ft_strncmp(argv[i], "-1", 2) != 0)
			flag = 0;
		else if (ft_atoi(argv[i]) == 0 && ft_strncmp(argv[i], "0", 1) != 0)
			flag = 0;
		else if (ft_atoi(argv[i]) == -1 && ft_strlen(argv[i]) != 2)
			flag = 0;
	}
	return (flag);
}

/**
 * DESCRIPTION:
 * Print information of errors.
 * PARAMETERS:
 * @param	int	code	Error code.
 */
void	print_error(int code)
{
	printf("Error: ");
	if (code == 1)
		printf("Wrong number of inputs");
	else if (code == 2)
		printf("Wrong format. Must be integers.");
	else if (code == 3)
		printf("Number zero isn't allowed.");
	else if (code == 4)
		printf("Negative numbers aren't allowed.");
	return ;
}

/**
 * DESCRIPTION:
 * Check all input exceptions.
 * PARAMETERS:
 * @param	int		argc	Number of elements of argv.
 * @param	char	**agv	Input paramenters from main.
 */
int	input_manager(int argc, char **argv)
{
	int	flag;

	printf("ARGC: %d\n", argc);
	flag = 0;
	if (argc < 4 || argc >= 6)
		flag = 1;
	else if (!chk_integer(argv))
		flag = 2;
	else if (!chk_zero(argv))
		flag = 3;
	else if (!chk_negative(argv))
		flag = 4;
	if (flag)
		print_error(flag);
	return (flag);
}
