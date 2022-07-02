
#include "../minishell.h"

void	ft_lstadd_front_env(t_env **alst, t_env *new)
{
	new->next = *alst;
	*alst = new;
}
