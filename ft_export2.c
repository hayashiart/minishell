/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 06:47:59 by slin              #+#    #+#             */
/*   Updated: 2022/10/12 06:48:01 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sub_free(char *str, char *end)
{
	if (set_env(str, end))
	{
		free(str);
		free(end);
		return (0);
	}
	free(str);
	free(end);
	return (1);
}

static void	modify(char **argv, char *str, int i)
{
	char	*end;
	int		count;

	count = 0;
	end = NULL;
	while (g_env[count])
		count++;
	count++;
	g_env = realloc_envs(count);
	str = ft_substr(argv[i], 0, ft_get_char_by_index(argv[i], '=') + 1);
	if (!str)
	{
		free(str);
		return ;
	}
	end = ft_substr(argv[i], ft_get_char_by_index(argv[i], '=') + 1,
			ft_strlen(argv[i]));
	if (!end)
	{
		free(str);
		return ;
	}
	g_env[count - 1] = ft_strjoin(str, end);
	free(str);
	free(end);
}

static int	set(char *arg, int equal_index, int index)
{
	char	*str;
	char	*end;
	int		equ_env;

	if (equal_index == (int)ft_strlen(arg))
		return (0);
	equ_env = ft_get_char_by_index(g_env[index], '=');
	if (equ_env == -1)
	{
		equ_env = ft_strlen(g_env[index]);
		g_env[index] = ft_strjoin(g_env[index], "=");
	}
	str = ft_substr(g_env[index], 0, equ_env);
	if (!str)
		return (0);
	end = ft_substr(arg, (equal_index + 1), ft_strlen(arg));
	return (sub_free(str, end));
}

void	add(char **argv, int i)
{
	int		index;
	int		equal_index;
	char	*str;

	equal_index = ft_get_char_by_index(argv[i], '=');
	if (equal_index == -1)
		equal_index = ft_strlen(argv[i]);
	str = ft_substr(argv[i], 0, equal_index);
	index = find_env_var(str);
	free(str);
	if (index != -1)
		set(argv[i], equal_index, index);
	else
		modify(argv, str, i);
}
