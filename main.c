#include "minishell.h"


char *rl_gets(int ac, char **av/*, char **env*/)
{
	static char *line_read = (char *)NULL;

	(void)ac;
	(void)av;
	if (line_read)
	{
		free (line_read);
		line_read = (char *)NULL;
	}
	line_read = readline ("\033[33mminishell\033[0m> ");
	if (line_read && *line_read)
	{
		add_history (line_read);
		if (!valid_quote(line_read))
			return(line_read);
		parser
	}
	return (line_read);
}

int main(int ac, char **av/*, char **env*/)
{
	while(rl_gets(ac, av/*, env*/))
		;
	printf("Bye \n");
}
