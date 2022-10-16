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

int	found_name(char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (g_env[i])
	{
		j = 0;
		k = 0;
		if (g_env[i][j] == to_find[k])
		{
			while (g_env[i][j] == to_find[k] && g_env[i][j] != '=')
			{
				j++;
				k++;
			}
			if (g_env[i][j] == '=' && !to_find[k])
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_getenv(char *to_find)
{
	int		i;
	int		j;
	int		k;
	char	*path;

	i = found_name(to_find);
	if (i == -1)
		return (NULL);
	path = malloc(4096 + 1);
	if (!path)
		return (printf("Malloc path failed\n"), NULL);
	j = 0;
	while (g_env[i][j])
		if (g_env[i][j++] == '=')
			break ;
	k = 0;
	while (g_env[i][j])
		path[k++] = g_env[i][j++];
	path[k] = 0;
	return (path);
}

static int	check_args(char **argv)
{
	int		i;
	char	*path;

	i = 0;
	while (argv[i])
		i++;
	if (i > 2)
		return (printf("minishell: cd: too many arguments\n"), EXIT_FAILURE);
	if (i == 1)
	{
		path = ft_getenv("HOME");
		if (!path)
			return (printf("minishell: cd: HOME not set\n"), EXIT_FAILURE);
		else
		{
			if (chdir(path))
				printf("minishell: cd: %s: Not a directory\n", path);
			return (free(path), EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_cd(char **argv)
{
	if (argv[1] && argv[1][0] == '\0')
		return (EXIT_SUCCESS);
	if (check_args(argv))
		return (EXIT_FAILURE);
	if (access(argv[1], F_OK))
	{
		printf("minishell: cd: %s No such file or directory\n", argv[1]);
		return (EXIT_FAILURE);
	}
	if (chdir(argv[1]) == -1)
		printf("minishell: cd: %s: Not a directory\n", argv[1]);
	return (EXIT_SUCCESS);
}
