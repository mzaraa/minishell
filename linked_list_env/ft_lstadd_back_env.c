
#include "../minishell.h"

void	ft_lstadd_back_env(t_env **alst, t_env *new)
{
	if (!*alst)
		*alst = new;
	else
		ft_lstlast_env(*alst)->next = new;
}
