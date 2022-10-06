/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:54:49 by slin              #+#    #+#             */
/*   Updated: 2022/09/22 04:54:52 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	found_name(char **env, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (env[i])
	{
		j = 0;
		k = 0;
		if (env[i][j] == to_find[k])
		{
			while (env[i][j] == to_find[k] && env[i][j] != '=')
			{
				j++;
				k++;
			}
			if (env[i][j] == '=' && !to_find[k])
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_getenv(char **env, char *to_find)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	i = found_name(env, to_find);
	if (i == -1)
		return (NULL);
	path = malloc(4096 + 1);
	if (!path)
		return (printf("Malloc path failed\n"), NULL);
	j = 0;
	while (env[i][j])
		if (env[i][j++] == '=')
			break ;
	k = 0;
	while (env[i][j])
		path[k++] = env[i][j++];
	path[k] = 0;
	return (path);
}

static int	check_args(char **args, char **env)
{
	int		i;
	char	*path;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
		return (printf("minishell: cd: too many arguments\n"), EXIT_FAILURE);
	if (i == 1)
	{
		if (found_name(env, "HOME") == -1)
			return (EXIT_FAILURE);
		path = ft_getenv(env, "HOME");
		printf("path = %s\n", path);
		if (!path)
			return (printf("minishell: cd: HOME not set\n"), EXIT_FAILURE);
		else
		{
			if (chdir(path) == -1)
				printf("minishell: cd: %s: Not a directory\n", path);
			return (free(path), EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_cd(char **args, char **env)
{
	if (args[1] && args[1][0] == '\0')
		return (EXIT_SUCCESS);
	if (check_args(args, env))
		return (EXIT_FAILURE);
	if (access(args[1], F_OK) == -1)
	{
		printf("minishell: cd: %s No such file or directory\n", args[1]);
		return (EXIT_FAILURE);
	}
	if (chdir(args[1]) == -1)
		printf("minishell: cd: %s: Not a directory\n", args[1]);
	return (EXIT_SUCCESS);
}
