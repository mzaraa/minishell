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

typedef struct s_tokens
{
    char*				token;
    struct s_tokens*	next;
}	t_tokens;

typedef struct s_data
{
    int			ac;
    char**		av;
    char**		env;
    t_tokens**	ll_token;
	char*		cmd;
}   t_data;

/* utils */
char*		ft_strtrim(char const	*s1, char const *set);
char*		ft_strchr(char *s, int c);
char*		ft_substr(char *s, unsigned int start, size_t len);
t_tokens*	ft_lstnew(char* content);
void		ft_lstadd_front(t_tokens **alst, t_tokens *new);
t_tokens*	ft_lstlast(t_tokens *lst);
void		ft_lstadd_back(t_tokens **alst, t_tokens *new);
int			ft_lstsize(t_tokens *lst);
void		ft_lstclear(t_tokens **lst);
void		ft_lstdelone(t_tokens *lst);

/* check quote*/
int     valid_quote(char* line_read);

/* lexer */
void	lexer(t_data *data);

char*	ft_strjoin(char* save, char* buffer);
size_t  ft_strlen(char* str);
char*   get_next_line(int fd);
char**  ft_split(char* s, char* charset);

#endif