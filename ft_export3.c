/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:46:04 by slin              #+#    #+#             */
/*   Updated: 2022/10/15 23:46:06 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	modify2(char *end, int len, int i)
{
	char	*tmp;
	char	*new;

	tmp = ft_substr(g_env[i], 0, (len + 1));
	if (!tmp)
		return (0);
	new = ft_strjoin(tmp, end);
	if (!new)
		return (0);
	free(g_env[i]);
	free(tmp);
	g_env[i] = new;
	return (1);
}

int	set_env(char *str, char *end)
{
	int		i;
	int		len;

	if (!str || !end)
		return (0);
	len = ft_strlen(str);
	i = -1;
	i = find_env_var(str);
	if (i != -1)
	{
		return (modify2(end, len, i));
	}
	return (0);
}

int	get_envs_count(void)
{
	int	count;

	count = 0;
	while (g_env[count])
		count++;
	return (count);
}

char	**realloc_envs(int size)
{
	char	**new;
	int		i;

	new = (char **)calloc(sizeof(char *), size + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (g_env[i] && i < size)
	{
		new[i] = ft_strdup(g_env[i]);
		i++;
	}
	new[size] = 0;
	ft_free_array(g_env);
	return (new);
}
