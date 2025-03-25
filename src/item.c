/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gaelchauvet@orange.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:59:49 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/25 02:02:25 by gchauvet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_item    *new_item(t_game *st_game, size_t x, size_t y)
{
    t_item	*new;

    new = malloc(sizeof(t_item));
    if (!new)
        return (NULL);
    new->x = x;
    new->y = y;
    new->next = st_game->st_item;
    st_game->st_item = new;
    return (new);
}