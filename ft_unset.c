/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:56:27 by slin              #+#    #+#             */
/*   Updated: 2022/09/22 04:56:29 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_var(char *var)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], var, ft_strlen(var)) == 0)
		{
			index = i;
			return (index);
		}
		i++;
	}
	return (-1);
}

static char	**erase_env(int index)
{
	int		j;
	int		len;
	char	**cpy;

	len = 0;
	while (g_env[len])
		len++;
	(cpy = (char **)ft_calloc(sizeof(char *), len));
	if (!cpy)
		return (NULL);
	j = -1;
	while (++j < index)
		cpy[j] = ft_strdup(g_env[j]);
	index++;
	while (g_env[index])
		cpy[j++] = ft_strdup(g_env[index++]);
	ft_free_array(g_env);
	return (cpy);
}

int	ft_unset(char **argv)
{
	int	i;
	int	index;

	i = 0;
	if (!argv[1])
		return (1);
	while (argv[++i])
	{
		index = find_env_var(argv[i]);
		if (index != -1)
		{
			if (g_env[index])
				g_env = erase_env(index);
		}
		else
		{
			ft_putstr_fd("minishell: unset: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("not a valid identifier\n", 2);
		}
	}
	return (1);
}
