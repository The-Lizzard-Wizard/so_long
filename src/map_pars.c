/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:54:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/24 16:45:28 by gchauvet         ###   ########.fr       */
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

int		check_size(t_game *game)
{
	size_t	l;
	size_t	c;
	size_t	size;

	l = 0;
	size = 0;
	while (game->st_map->map[l])
	{
		c = 0;
		while (game->st_map->map[l][c])
			c++;
		if (c != ft_strlen(game->st_map->map[0]))
			return (0);
		l++;
	}
	game->st_map->size_l = l;
	game->st_map->size_c = c;
	return (1);
}

int		check_wall(t_game *game)
{
	(void)game;
	return (0);
}

int		check_map(t_game *game)
{
	if (!check_size(game))
		return (0);
	//if (!check_wall(game))
	//	return (0);
	return (1);
}
