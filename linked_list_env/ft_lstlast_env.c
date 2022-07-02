
#include "../minishell.h"

//Renvoie le dernier élément de la liste.
t_env	*ft_lstlast_env(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
