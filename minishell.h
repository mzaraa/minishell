/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:56:00 by mzaraa            #+#    #+#             */
/*   Updated: 2022/06/26 15:56:01 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define METACHAR " \t\n|&<>"
# define BOLDBLUE "\001\033"
# define RESET "\001\033[0m\002"

enum	e_type
{
	PIPE,
	REDIRECTION,
	WORD,
};

typedef struct s_tokens
{
	char			*token;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_data
{
	int				ac;
	char			**av;
	char			**env;
	t_tokens		**ll_token;
	char			*cmd;
	struct s_tree	**ast_tree;
}	t_data;

typedef struct s_tree
{
	char			*token;
	int				type;
	void			(*function)(t_data*);
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

/* utils */
char		*ft_strtrim(char const	*s1, char const *set);
char		*ft_strchr(char *s, int c);
char		*ft_substr(char *s, unsigned int start, size_t len);
t_tokens	*ft_lstnew(char *content);
void		ft_lstadd_front(t_tokens **alst, t_tokens *new);
t_tokens	*ft_lstlast(t_tokens *lst);
void		ft_lstadd_back(t_tokens **alst, t_tokens *new);
int			ft_lstsize(t_tokens *lst);
void		ft_lstclear(t_tokens **lst);
void		ft_lstdelone(t_tokens *lst);
char		*ft_strdup(const char *s1);
void		free_tree(t_tree **tree);

/* check quote*/
int			valid_quote(char *line_read);

/* lexer / parser */
void		parser(t_data *data);
void		lexer(t_data *data);
t_tree		*ft_tree_new_node(char *token);
void		build_tree(t_tree **data, t_tree *node);

char		*ft_strjoin(char *save, char *buffer);
size_t		ft_strlen(char *str);
char		*get_next_line(int fd);
char		**ft_split(char *s, char *charset);

#endif