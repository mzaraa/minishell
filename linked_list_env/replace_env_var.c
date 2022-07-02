#include "../minishell.h"

static void	swap(t_tokens **node, t_tokens **prev_node, char *value)
{
	t_tokens	*new_node;

	new_node = ft_lstnew(value);
	(*prev_node)->next = new_node;
	new_node->next = (*node)->next;
}

void	env_var_to_value(t_data *data)
{
	t_tokens	*node;
	t_tokens	*prev_node;
	t_env		*temp_env;

	node = *(data->ll_token);
	prev_node = node;
	temp_env = *(data->ll_env);
	while (node)
	{
		if (*(node->token) == '$')
			while (temp_env)
			{
				if (!(strcmp(temp_env->var, (node->token + 1))))
				{
					swap(&node, &prev_node, temp_env->value);
					break ;
				}
				temp_env = temp_env->next;
			}
		prev_node = node;
		node = node->next;
	}
}
