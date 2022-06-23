#include "minishell.h"

void print_list(t_data *data)
{
	t_tokens* temp;

	temp = *(data->ll_token);
	while (temp)
	{
		printf("%s \n", temp->token);
		temp = temp->next;
	}
}

char *rl_gets(t_data *data)
{
	static char *line_read = (char *)NULL;

	if (line_read)
	{
		free (line_read);
		ft_lstclear(data->ll_token);
		line_read = (char *)NULL;
		data->cmd = NULL;
	}
	line_read = readline ("\033[33mminishell\033[0m> ");
	if (line_read && *line_read)
	{
		add_history (line_read);
		if (!valid_quote(line_read))
			return(line_read);
		data->cmd = line_read;
		lexer(data);
		parser(data);
		// print_list(data);
	}
	return (line_read);
}

int main(int ac, char **av, char **env)
{
	t_data		data;
	t_tokens*	tokens;
	t_tree*		node;

	tokens = NULL;
	node = NULL;
	data.ac = ac;
	data.av = av;
	data.env = env;
	data.ll_token = &tokens;
	data.cmd = NULL;
	data.ast_tree = &node;
	while(rl_gets(&data))
		;
	printf("Bye \n");
}
