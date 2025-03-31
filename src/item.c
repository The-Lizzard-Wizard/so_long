/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:59:49 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/31 13:50:18 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "stdlib.h"

t_item    *new_item(t_game *game, t_map *st_map, size_t x, size_t y)
{
    t_item	*new;

    new = malloc(sizeof(t_item));
    if (!new)
        return (NULL);
    new->x = x;
    new->y = y;
    new->next = game->st_item;
    game->st_item = new;
    st_map->nb_item++;
    return (new);
}