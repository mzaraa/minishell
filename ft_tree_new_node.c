#include "minishell.h"

t_tree*	ft_tree_new_node(char*	token)
{
	t_tree*	new_node;

	new_node = malloc(sizeof(t_tree));
	new_node->token = strdup(token);
	new_node->left = NULL;
	new_node->right = NULL;
	if(*token == '|' && !(*(token + 1)))
	{
		new_node->type = pipe;
		new_node->function = pipe_function; // to do
	}
	else
	{
		new_node->type = word;
		new_node->function = cmd_function; // to do
	}
	return (new_node);
}
