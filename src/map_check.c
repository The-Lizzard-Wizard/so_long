/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:52 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/31 13:24:21 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stddef.h>

int	is_wall(t_map *st_map, size_t l, size_t c)
{
	size_t	i;

	i = 0;
	while (st_map->id_wall[i])
	{
		if (st_map->map[l][c] == st_map->id_wall[i])
			return (1);
		i++;
	}
	i = 0;
	while (st_map->id_floor[i])
	{
		if (st_map->map[l][c] == st_map->id_floor[i])
			return (2);
		i++;
	}
	return (0);
}

int		check_wall(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->st_map->map[0][++i])
		if (is_wall(game->st_map, 0, i) != 1)
			return (0);
	i = 0;
	while (game->st_map->map[game->st_map->size_l - 1][++i])
		if (is_wall(game->st_map, game->st_map->size_l - 1, i) != 1)
			return (0);
	i = 0;
	while (++i < game->st_map->size_l - 1)
		if (is_wall(game->st_map, i, 0) != 1)
			return (0);
	i = 0;
	while (++i < game->st_map->size_l - 1)
		if (is_wall(game->st_map, i, game->st_map->size_c - 1) != 1)
			return (0);
	return (1);
}

void	flood_fill(t_game *game, t_map *st_tmp_map, size_t l, size_t c)
{
	if (is_wall(st_tmp_map, l, c) == 2)
	{
		st_tmp_map->map[l][c] = 'V';
		flood_fill(game, st_tmp_map, l + 1, c);
		flood_fill(game, st_tmp_map, l - 1, c);
		flood_fill(game, st_tmp_map, l, c + 1);
		flood_fill(game, st_tmp_map, l, c - 1);
	}
}

int	flood_fill_check(t_game *game)
{
	t_map	*st_tmp_map;
	
	st_tmp_map = pars(game->st_map->path);
	init_texture_id(game, st_tmp_map);
	flood_fill(game, st_tmp_map, game->st_player->y, game->st_player->x);
	init_info(game, st_tmp_map, 0);
	if (st_tmp_map->nb_exit != 0 || st_tmp_map->nb_item != 0 || st_tmp_map->nb_player != 0)
		return (0);
	free_map(st_tmp_map);
	return (1);
}

int		check_map(t_game *game)
{
	init_texture_id(game, game->st_map);
	if (!check_size(game))
		return (0);
	if (!check_wall(game))
		return (0);
	if (!flood_fill_check(game))
		return (0);
	if (game->st_map->nb_item < 1 || game->st_map->nb_player != 1 || game->st_map->nb_exit != 1)
		return (0);
	return (1);
}
