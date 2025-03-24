#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>

typedef struct s_map
{
	char			**map;
	size_t			size_l;
	size_t			size_c;
}	t_map;

t_map	*pars(char **argv);
void	print_map(t_map *st_map);
int		check_map(t_map *st_map);
int    check_size(t_map *st_map);

#endif