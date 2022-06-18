#include "minishell.h"

static int s_quote(char* line_read)
{
	char quote = '\'';
	while(*line_read)
	{
		if (*line_read == quote)
		{
			line_read = strchr(++line_read, quote);
			if (!line_read)
				return (0);
		}
		line_read++;
	}
	return (1);
}

static int d_quote(char* line_read)
{
	char quote = '\"';
	while(*line_read)
	{
		if (*line_read == quote)
		{
			line_read = strchr(++line_read, quote);
			if (!line_read)
				return (0);
		}
		line_read++;
	}
	return (1);
}


int valid_quote(char* line_read)
{
	puts("fdsfvhdso");
	if (!s_quote(line_read))
	{
		printf("Erreur de quotes\n");
		return(0);
	}
	if (!d_quote(line_read))
	{
		printf("Erreur de quotes\n");
		return(0);
	}
	return (1);
}