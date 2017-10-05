#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/libft.h"
#include "fillit.h"

void	print_error(char *msg)
{
	if(msg)
	{
		ft_putstr_fd("Error: ", 1);
		ft_putendl_fd(msg, 1);
	}
	else
		ft_putendl_fd("Error: ", 1);
	exit(-1);
}

int		main(int argc, char *argv[])
{
	int		i;
	int 	fd;
	char	c;
	//t_map map;
	i = 0;
	t_fig	*out;

	if(argc !=2)
	{
		print_error("Usage: ./fillit [map.map]");
		return(0);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		print_error("An error occured during opening of the file");
	t_fig = read_map(fd, i, c, out);
	//ft_memset(&map, 0, sizeof(map));
	ft_readmap();
	//parse(fd, &map);
	close(fd);
	//solve(&map);
	return(1);
}