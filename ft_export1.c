/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 04:56:47 by slin              #+#    #+#             */
/*   Updated: 2022/09/22 04:56:48 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_export_name(char *str)
{
	int		i;
	int		alpha_found;

	i = 0;
	alpha_found = 0;
	if (!str || !str[0] || str[0] == '=')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalpha(str[i]))
			alpha_found = 1;
		else
		{
			if (ft_isdigit(str[i]) && !alpha_found)
				return (0);
			else if (!ft_isdigit(str[i]) && str[i] != '_')
				return (0);
		}
		i++;
	}
	return (1);
}

static void	print_export(char **export)
{
	int	i;
	int	j;
	int	equ;

	i = 0;
	while (export[i])
	{
		equ = 1;
		j = 0;
		ft_putstr_fd("declare -x ", 1);
		while (export[i][j])
		{
			ft_putchar_fd(export[i][j], 1);
			if (export[i][j] == '=' && equ)
			{
				ft_putchar_fd('"', 1);
				equ--;
			}
			j++;
		}
		if (!equ)
			ft_putchar_fd('"', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

static char	**dup_env(void)
{
	char				**dup;
	int					count;
	int					i;

	count = 0;
	while (g_env[count])
		count++;
	dup = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < count)
	{
		dup[i] = ft_strdup(g_env[i]);
		i++;
	}
	dup[count] = 0;
	return (dup);
}

static void	sort_env(void)
{
	char	**dup;
	char	*tmp;
	int		i;
	int		j;

	dup = dup_env();
	i = 0;
	while (dup[i])
	{
		j = i + 1;
		while (dup[j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_export(dup);
	ft_free_array(dup);
}

int	ft_export(char **argv)
{
	int	i;

	if (!argv[1])
	{
		sort_env();
		return (1);
	}
	i = 0;
	while (argv[++i])
	{
		if (!check_export_name(argv[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			continue ;
		}
		add(argv, i);
		sort_env();
	}
	return (1);
}
