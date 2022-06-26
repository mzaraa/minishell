#include "minishell.h"

void	parser(t_data* data)
{
	t_tokens*	temp;

	temp = *(data->ll_token);
	while(temp != NULL)
	{
		build_tree(data->ast_tree, ft_tree_new_node(temp->token));
		temp = temp->next;
	}
}
