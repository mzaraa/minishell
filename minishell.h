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

/* utils */
char	*ft_strchr(char *s, int c);
int     valid_quote(char* line_read);

char	*ft_strjoin(char *save, char *buffer);
size_t	ft_strlen(char *str);
char*   get_next_line(int fd);
char**  ft_split(char *s, char *charset);

#endif