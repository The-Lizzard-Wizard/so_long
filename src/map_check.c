/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:52 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/25 15:42:56 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_wall(t_game *game, size_t l, size_t c)
{
	size_t	i;

	i = 0;
	while (game->st_map->id_wall[i])
	{
		if (game->st_map->map[l][c] == game->st_map->id_wall[i])
			return (1);
		i++;
	}
	i = 0;
	while (game->st_map->id_floor[i])
	{
		if (game->st_map->map[l][c] == game->st_map->id_floor[i])
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
		if (is_wall(game, 0, i) != 1)
			return (0);
	i = 0;
	while (game->st_map->map[game->st_map->size_l - 1][++i])
		if (is_wall(game, game->st_map->size_l - 1, i) != 1)
			return (0);
	i = 0;
	while (++i < game->st_map->size_l - 1)
		if (is_wall(game, i, 0) != 1)
			return (0);
	i = 0;
	while (++i < game->st_map->size_l - 1)
		if (is_wall(game, i, game->st_map->size_c - 1) != 1)
			return (0);
	return (1);
}

int	flood_fill()
{
	
	return (1);
}

int		check_map(t_game *game)
{
	init_texture_id(game);
	if (!check_size(game))
		return (0);
	if (!check_wall(game))
		return (0);
	return (1);
}
