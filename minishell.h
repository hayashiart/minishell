/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 06:08:13 by slin              #+#    #+#             */
/*   Updated: 2022/10/16 06:08:14 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <signal.h>

# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"
# define ENDC "\033[0m"
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERROR 1
# define SUCCESS 0
# define BUFF_SIZE 4096

extern char	**g_env;

int			ft_echo(char **argv);
int			ft_cd(char **argv);
int			ft_env(void);
int			ft_pwd(void);
int			ft_exit(char **argv);
int			ft_unset(char **argv);
int			find_env_var(char *var);
int			ft_get_char_by_index(char *str, char c);
char		**realloc_envs(int size);
int			ft_export(char **argv);
void		add(char **argv, int i);
int			set_env(char *env, char *new_env);
int			get_envs_count(void);
int			g_env_init(char **env);
void		print_g_env(void);

#endif
