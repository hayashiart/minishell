#include "minishell.h"

char **g_env;

int	g_env_init(char **env)
{
	int	i;

	i = 0;
	int	size;
	size = 0;
	while(env[size])
		size++;
	if(!(g_env= (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	while (env[i])
	{
		g_env[i] = ft_strdup(env[i]);
		i++;
	}
	g_env[i] = 0;
	return (1);
}

void	print_g_env(void)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		//ft_putendl_fd(g_env[i], 1);
		printf("g_env[%d] = %s\n", i, g_env[i]);
		i++;
	}
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	if (!(g_env_init(env)))
		return (0);

/* TEST CD
	char buf[4096];
	printf("current directory = %s\n", getcwd(buf, 4096));
	ft_cd(argv);
	printf("current directory = %s\n", getcwd(buf, 4096));
*/

/* TEST ECHO
	ft_echo(argv);
*/

/* TEST ENV
	ft_env();
*/

/* TEST EXIT
	ft_exit();
*/

/* TEST EXPORT
	ft_export(argv);
*/

/* TEST PWD
	ft_pwd();
*/

/* TEST UNSET
	print_g_env();
	ft_unset(argv);
	print_g_env();
	ft_free_array(g_env);	
*/
}