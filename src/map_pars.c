/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:54:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/25 18:19:19 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../inc/so_long.h"

t_map	*pars(char *path)
{
	t_map	*st_map;
	int		ber;
	char	*line;
	char	*map_line;

	line = NULL;
	map_line = ft_strdup("");
	ber = open(path, O_RDONLY);
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
	st_map->path = path;
	return (st_map);
}

void	store_data(t_game *game)
{
	size_t	l;
	size_t	c;

	l = 0;
	while (game->st_map->map[l])
	{
		c = 0;
		while (game->st_map->map[l][c])
		{
			if (game->st_map->map[l][c] == 'P')
			{
				game->st_player->x = c;
				game->st_player->y = l;
			}
			c++;
		}
		l++;
	}
}

int		check_size(t_game *game)
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

void	init_info(t_game *game ,t_map *st_map, int initp)
{
	size_t	l;
	size_t	c;

	l = 0;
	while (st_map->map[l])
	{
		c = 0;
		while (st_map->map[l][c])
		{
			if (st_map->map[l][c] == 'E')
				st_map->nb_exit++;
			if (st_map->map[l][c] == 'P')
				st_map->nb_player++;
			if (st_map->map[l][c] == 'C')
				st_map->nb_item++;
			c++;
		}
		l++;
	}
	if (initp == 1)
		init_player(game);
}

void	init_texture_id(t_game *game, t_map *st_map)
{
	st_map->id_wall[0] = '1';
	st_map->id_wall[1] = '2';
	st_map->id_wall[2] = '\0';
	st_map->id_floor[0] = '0';
	st_map->id_floor[1] = 'P';
	st_map->id_floor[2] = 'C';
	st_map->id_floor[3] = 'E';
	st_map->id_floor[4] = '\0';
	if (!game)
		return ;
}
