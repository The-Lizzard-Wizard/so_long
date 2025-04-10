/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:59:49 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/09 16:34:26 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "stdlib.h"
#include <unistd.h>

t_item	*new_item(t_game *game)
{
	t_item	*new;

	new = NULL;
	new = malloc(sizeof(t_item));
	if (!new)
		close_window(game, 1, "Error\nitem load failed\n", EXIT_FAILURE);
	new->x = 0;
	new->y = 0;
	new->collect = 0;
	new->next = NULL;
	return (new);
}

t_item	*add_item(t_game *game, t_map *st_map, size_t x, size_t y)
{
	t_item	*new;

	new = NULL;
	new = new_item(game);
	if (!new)
		close_window(game, 1, "Error\nitem load failed\n", EXIT_FAILURE);
	new->x = x;
	new->y = y;
	new->next = game->st_item;
	game->st_item = new;
	st_map->nb_item++;
	return (new);
}

void	init_index_null(t_map *st_map)
{
	st_map->id_floor = NULL;
	st_map->id_wall = NULL;
}
