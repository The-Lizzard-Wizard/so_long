/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:59:49 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/02 13:42:24 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/libft.h"
#include "stdlib.h"

t_item    *new_item(t_game *game)
{
    t_item	*new;

    new = malloc(sizeof(t_item));
    if (!new)
    {
        free_game(game);
        return (NULL);
    }
    new->x = 0;
    new->y = 0;
    new->next = NULL;
    return (new);
}

t_item    *add_item(t_game *game, t_map *st_map, size_t x, size_t y)
{
    t_item	*new;

    // if (st_map->nb_item > 0)
    // {
        new = new_item(game);
        if (!new)
            return (NULL);
        new->x = x;
        new->y = y;
        new->next = game->st_item;
        game->st_item = new;
    // }
    // else
    // {
    //     new = new_item(game);
    //     if (!new)
    //         return (NULL);
    //     new->x = x;
    //     new->y = y;
    // }
    st_map->nb_item++;
    return (new);
}
