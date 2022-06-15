#include "minishell.h"

/* Read a string, and return a pointer to it.
   Returns NULL on EOF. */
char *rl_gets(int ac, char **av, char **env)
{
	static char *line_read = (char *)NULL;
	char	*pathvar = env[13];
	char	**path = ft_split(pathvar, ":");

	(void)ac;
	(void)av;
	printf ("path: %s\n", pathvar);
	while(*path)
	{
		printf ("path: %s\n", *path);
		path++;
	}
	/* A static variable for holding the line. */
	/* If the buffer has already been allocated,
	return the memory to the free pool. */
	if (line_read)
	{
		free (line_read);
		line_read = (char *)NULL;
	}
	/* Get a line from the user. */
	line_read = readline ("hello> ");
	printf("line_read: %s\n", line_read);
	/* If the line has any text in it,
		save it on the history. */
	if (line_read && *line_read)
		add_history (line_read);

	return (line_read);
}

int main(int ac, char **av, char **env)
{
	while(rl_gets(ac, av, env))
		;
	printf("Bye \n");
}
