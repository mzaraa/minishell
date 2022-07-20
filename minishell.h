/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:56:00 by mzaraa            #+#    #+#             */
/*   Updated: 2022/07/20 16:54:58 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define METACHAR	" \t\n|&<>"
# define BOLDBLUE	"\001\033"
# define RESET		"\001\033[0m\002"
# define NOTHING	0
# define SIMPLE_Q	1
# define DOUBLE_Q	2

typedef struct s_data	t_data;

enum	e_type
{
	PIPE,
	REDIRECTION,
	WORD,
};

typedef struct s_tokens
{
	char			*token;
	int				state;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_tree
{
	char			*token;
	int				type;
	void			(*function)(t_data*, struct s_tree*);
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

struct s_data
{
	int				ac;
	char			**av;
	char			**env;
	t_tokens		**ll_token;
	char			*cmd;
	t_tree			**ast_tree;
	t_env			**ll_env;
	int				status;
	pid_t			pid;
	int				exit_code;
	int				is_sig;

};

void		rl_replace_line(const char *text, int clear_undo);

/* utils tokens*/
t_tokens	*ft_lstnew(char *content);
void		ft_lstadd_front(t_tokens **alst, t_tokens *new);
t_tokens	*ft_lstlast(t_tokens *lst);
void		ft_lstadd_back(t_tokens **alst, t_tokens *new);
int			ft_lstsize(t_tokens *lst);
void		ft_lstclear(t_tokens **lst);
void		ft_lstdelone(t_tokens *lst);
char		*ft_strdup(const char *s1);

/* utils env */
void		env_var_to_value(t_data *data);
t_env		*get_env(char **env);
t_env		*ft_lstnew_env(char *var, char *value);
void		ft_lstadd_front_env(t_env **alst, t_env *new);
t_env		*ft_lstlast_env(t_env *lst);
void		ft_lstadd_back_env(t_env **alst, t_env *new);
int			ft_lstsize_env(t_env *lst);
void		ft_lstclear_env(t_env **lst);
void		ft_lstdelone_env(t_env *lst);
void		replace_in_quote(t_data *data, t_env **env, t_tokens *node);
void		ft_trim_d_quote(t_tokens *node);
void		ft_trim_s_quote(t_tokens *node);
void		change_env(t_data *data, t_env **env);
void		free_env(char **env);

/* check quote*/
int			valid_quote(char *line_read);

/* lexer / parser */
void		parser(t_data *data);
void		lexer(t_data *data);
t_tree		*ft_tree_new_node(char *token);
void		build_tree(t_tree **data, t_tree *node);
void		free_tree(t_tree **tree);
void		pipe_init(t_data *data, t_tree *node);
void		word_check(t_data *data, t_tree *node);
void		ft_error_path(char *cmd);

/* builtin*/
int			is_builtin(t_data *data, t_tree *node, char	*cmd);
void		ft_env(t_data *data, t_tree *node);
void		ft_export(t_data *data, t_tree *node);
int			ft_isalnum(int c);
void		ft_unset(t_data *data, t_tree *node);
void		ft_pwd(t_data *data, t_tree *node);
void		ft_cd(t_data *data, t_tree *node);
void		ft_execve(t_data *data, t_tree *node, char *cmd);
void		ft_exit(t_data *data, t_tree *node);

int			recup_var_name(char c);
int			check_char_for_var(char c);
int			state(t_tokens *node, int i);
int			var_to_val(t_data *data, t_tokens *node, char *temp, int j);

/* print list and tree*/
void		print_list_token(t_data *data);
void		print_list_env(t_data *data);
void		print_tree(t_tree *tree);
void		print_list_env_only_export(t_data *data);
int			ft_strcmp(const char *s1, const char *s2);

/* mini_libft */
char		*ft_strjoin(char *save, char *buffer);
size_t		ft_strlen(char *str);
char		*get_next_line(int fd);
char		**ft_split(char *s, char *charset);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strchr(char *s, int c);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_itoa(int n);
void		free_all(char **tab);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_trim_s_quote(t_tokens *node);
char		*join_three(char *s1, char *s2, char *s3);
void		ft_substrcat(char *dst, char *src, size_t n_byte);
void		*ft_calloc(size_t count, size_t size);

void		handle_sig(int sig);
int			get_status(t_data *datas, int status);

#endif