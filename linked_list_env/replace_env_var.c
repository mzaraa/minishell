#include "../minishell.h"

void	env_var_to_value(t_data *data)
{
	t_tokens	*temp_token;
	t_tokens	*prev_token;
	t_tokens	*new_node;
	t_env		*temp_env;

	temp_token = *(data->ll_token);
	prev_token = temp_token;
	temp_env = *(data->ll_env);
	while (temp_token)
	{
		if (*(temp_token->token) == '$')
			while (temp_env)
			{
				if (!(strcmp(temp_env->var, (temp_token->token + 1))))
				{
					new_node = ft_lstnew(temp_env->value);
					prev_token->next = new_node;
					new_node->next = temp_token->next;
					break ;
				}
				temp_env = temp_env->next;
			}
		prev_token = temp_token;
		temp_token = temp_token->next;
	}
}
