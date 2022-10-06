/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:19:02 by slin              #+#    #+#             */
/*   Updated: 2022/09/22 02:19:04 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	nb_args(char **argv)
{
	int	size;

	size = 0;
	while (argv[size])
	{
		size++;
	}
	return (size);
}

int	ft_echo(char **argv)
{
	int	i;
	int	n_option;

	n_option = 0;
	i = 1;
	if (argv[i] && ft_strcmp(argv[i], "-n") == 0)
	{
		n_option = 1;
		i++;
	}
	if (nb_args(argv) > 1)
	{
		while (argv[i])
		{
			ft_putstr_fd(argv[i], 1);
			if (argv[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (1);
}
