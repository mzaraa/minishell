#include "../minishell.h"

void	free_tree(t_tree **tree)
{
	if (!*tree)
		return ;
	t_tree	*tmp;

	tmp = *tree;
	if(tmp)
	{
		free_tree(&tmp->right);
		free_tree(&tmp->left);
	}
	free(tmp);
	*tree = NULL;
}