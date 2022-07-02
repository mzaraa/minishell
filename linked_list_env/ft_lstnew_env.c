
#include "../minishell.h"

/*
Alloue et renvoie un nouvel élément. la variable content est initialisée à 
l’aide de la valeur du paramètre content. 
La variable ’next’ est initialisée à NULL.
*/

t_env	*ft_lstnew_env(char *var, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->var = var;
	node->value = value;
	node->next = NULL;
	return (node);
}
