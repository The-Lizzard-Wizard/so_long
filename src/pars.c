/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:54:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/24 12:04:13 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../inc/so_long.h"

t_map	*pars(char **argv)
{
	t_map	*st_map;
	int		ber;
	char	*line;
	char	*map_line;

	line = NULL;
	map_line = ft_strdup("");
	ber = open(argv[1], O_RDONLY);
	if (ber == -1)
		return (NULL);
	line = get_next_line(ber);
	while (line)
	{
		map_line = ft_strjoin(map_line, line);
		free(line);
		line = get_next_line(ber);
	}
	st_map = malloc(sizeof(t_map));
	st_map->map = ft_split(map_line, '\n');
	return (st_map);
}

int		check_size(t_map *st_map)
{
	size_t	l;
	size_t	c;
	size_t	size;

	l = 0;
	size = 0;
	while (st_map->map[l])
	{
		c = 0;
		while (st_map->map[l][c])
			c++;
		if (c != ft_strlen(st_map->map[0]))
			return (0);
		l++;
	}
	st_map->size_l = l;
	st_map->size_c = c;
	return (1);
}

int		check_wall(t_map *st_map)
{
	while (st_map->map)
	{
	}
	return (0);
}

int		check_map(t_map *st_map)
{
	if (!check_size(st_map))
		return (0);
	// if (!check_wall(st_map))
	// 	return (0);
	return (1);
}

void	print_map(t_map *st_map)
{
	size_t	l;

	l = 0;
	while (st_map->map[l])
	{
		ft_printf("%s\n", st_map->map[l]);
		l++;
	}
	ft_printf("size l : %i\n", st_map->size_l);
	ft_printf("size c : %i\n", st_map->size_c);
}
