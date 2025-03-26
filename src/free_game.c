/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:50:00 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/26 16:05:05 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/so_long.h"

void	free_game(t_game *game)
{
    free_map(game->st_map);
    free(game->st_player);
    //free(game->st_item);
    free(game);
}