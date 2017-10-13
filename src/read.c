#include "../includes/fillit.h"

int		check_figures(char *figure)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ft_strcmp(figure, "#.#\n#.#\n") || !ft_strcmp(figure, "##\n..\n##\n"))
		return (0);
	while (*figure)
	{
		if (*figure == '#')
			i++;
		if (*figure == '.')
			j++;
		figure++;
	}
	if (i == 4 && (j == 2 || j == 0))
		return (1);
	return (0);
}

int		check_empty(char *str)
{

	int	i;
	if(!str)
		return(1);
	i = 0;
	while(str[i])
	{
		if(str[i++] == '#')
			return(0);
	}
	return(1);
}

void	trim_map(char *buff)
{
	char	**split;
	int		i;
	int		end;

	i = 0;
	split = ft_strsplit(buff, '\n');

	while (check_empty(split[i]) && i < 4)
		i++;
	end = i;
	
	while (!check_empty(split[end]) && end < 4)
		end++;
	ft_strclr(buff);
	while (i < end)
	{
		ft_strcat(buff, (mem_line(split[i], fn_start(split), fn_last(split))));
		i++;
	}
}

int		map_validation(char *buff, int size)
{
	int		i;
	int		j;

	i = 0;


	while (i < size)
	{	
		j = 0 ;
		while (buff[i] == '#' || buff[i] == '.')
		{
			i++;
			j++;
		}
		if (buff[i++] == '\n' && j == 4)
			continue;
		return (0);
	}
	return (1);
}

void	check_map(t_fig **out, char buff[21], char ch)
{
	//char	**split;
	ch = 0;
	out = NULL;
	if (!map_validation(buff, 20))
		print_error("invalid map");
	trim_map(buff);
	ft_putendl(buff);
	/*if (check_figures(buff))
	{
		split = ft_strsplit(buff, '\n');
		//set_chars(split, ch);
		//ft_lstcadd(out, &split);
	}
	else
		ft_error();
		*/
}

t_fig	*read_map(int fd, int i, char ch, t_fig *out)
{
	int j;
	char buff[21];

	j = 0;
	ch = 'A';
	while(1 && (j != 1))
	{
		if ((i = read(fd, buff, 21)) == 21)
			j = 1;
		if ((i == 20 || i == 21) && !(buff[20] = 0))
		{
			check_map(&out, buff, ch++);
			if (!j)
				break ;
		}
		else
			print_error("Map check error");
	}
	return (out);
}