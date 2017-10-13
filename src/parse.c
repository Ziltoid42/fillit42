#include "../includes/fillit.h"

char *mem_line(char *line, int start, int end)
{
	char *tmp;
	int i;

	i = 0;
	tmp = (char *)malloc(end - start + 3);
	while(start <= end)
		tmp[i++] = line[start++];
	tmp[i++] = '\n';
	tmp[i] = '\0';
	return (tmp);
}

int		fn_start(char **split)
{
	int i;
	int k;

	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (split[k++][i] == '#')
				return (i);
		}
		i++;
	}
	return (0);
}

int		fn_last(char **split)
{
	int i;
	int k;
	int	last;

	i = 0;
	last = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (split[k][i] == '#')
			{
				last = i;
				break ;
			}
			k++;
		}
		i++;
	}
	return (last);
}