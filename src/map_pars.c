/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:54:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/29 17:33:26 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../inc/so_long.h"

t_map	*pars(t_game *game, char *path)
{
	t_map	*st_map;
	int		ber;
	char	*line;
	char	*map_line;

	line = NULL;
	ber = open(path, O_RDONLY);
	if (ber == -1)
		close_window(game, 1, "Error\nfiles opening failed\n", EXIT_FAILURE);
	map_line = NULL;
	line = get_next_line(ber);
	while (line)
	{
		map_line = ft_strjoin(map_line, line);
		free(line);
		line = get_next_line(ber);
	}
	st_map = malloc_map(game, ber, line, map_line);
	st_map->path = ft_strdup(path);
	close(ber);
	free(line);
	free(map_line);
	check_map_info(game, st_map);
	return (st_map);
}

void	init_exit(t_game *game, t_map *st_map, size_t l, size_t c)
{
	if (game)
	{
		st_map->exit_x = c;
		st_map->exit_y = l;
		st_map->nb_exit++;
	}
}

int	check_size(t_game *game)
{
	size_t	l;
	size_t	c;

	l = 0;
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

void	init_info(t_game *game, t_map *st_map, int initp)
{
	size_t	l;
	size_t	c;

	l = 0;
	st_map->nb_exit = 0;
	st_map->nb_player = 0;
	st_map->nb_item = 0;
	while (st_map->map[l])
	{
		c = 0;
		while (st_map->map[l][c])
		{
			if (st_map->map[l][c] == 'E')
				init_exit(game, st_map, l, c);
			if (st_map->map[l][c] == 'P')
				st_map->nb_player++;
			if (st_map->map[l][c] == 'C')
				add_item(game, st_map, c, l);
			c++;
		}
		l++;
	}
	if (initp == 1)
		init_player(game);
}

void	init_texture_id(t_game *game, t_map *st_map)
{
	st_map->id_wall = ft_strdup("1");
	st_map->id_floor = ft_strdup("0PCE");
	if (!st_map->id_floor || !st_map->id_wall)
		close_window(game, 0, NULL, EXIT_FAILURE);
}
