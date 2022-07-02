
#include "../minishell.h"

void	ft_lstclear_env(t_env **lst)
{
	t_env	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone_env(temp);
	}
}
