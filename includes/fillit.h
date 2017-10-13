#ifndef FILLIT_H
# define FILLIT_H

# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_fig
{
	char			**figure;
	struct s_fig	*next;
}					t_fig;

/*
**				read.c
*/
int		check_figures(char *figure);
int		check_empty(char *str);
void	trim_map(char *buff);
void	check_map(t_fig **out, char buff[21], char c);
t_fig	*read_map(int fd, int i, char ch, t_fig *out);

/*
**				parse.c
*/

char *mem_line(char *line, int start, int end);
int		fn_start(char **split);
int		fn_last(char **split);

/*
**				main.c
*/

void	print_error(char *msg);


#endif