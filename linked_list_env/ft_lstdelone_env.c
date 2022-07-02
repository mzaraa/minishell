
#include "../minishell.h"

/*
Libère la mémoire de l’élément passé en argument
en utilisant la fonction del puis avec free. La
mémoire de next ne doit pas être free.
*/
void	ft_lstdelone_env(t_env *lst)
{
	if (lst)
		free (lst);
}
