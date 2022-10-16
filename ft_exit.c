/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:55:26 by slin              #+#    #+#             */
/*   Updated: 2022/09/22 04:55:27 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
static void	free_param(t_data *param)
{
	free(param);
}*/

int	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **argv)
{
	int	i;
	int	status;

	status = 0;
	i = 0;
	if (argv[1] && argv[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		status = 1;
	}
	else if (argv[1] && ft_strisnum(argv[1]) == 0)
	{
		status = 255;
		ft_putstr_fd("minishell: exit:", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (argv[1])
	{
		status = ft_atoi(argv[1]) % 256;
	}
	else
		status = 0;
	/*free_param(param);*/
	exit(status);
}
