#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
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
	int fd;
	//t_map map;

	if(argc !=2)
	{
		print_error("Usage: ./fillit [map.map]");
		return(0);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		print_error("An error occured during opening of the file");
	//ft_memset(&map, 0, sizeof(map));
	//parse(fd, &map);
	close(fd);
	//solve(&map);
	return(1);
}