/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:25:12 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/09 16:34:18 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>

void	init_player(t_game *game)
{
	size_t	l;
	size_t	c;

	game->st_player.mushroom = 0;
	l = 0;
	while (game->st_map->map[l])
	{
		c = 0;
		while (game->st_map->map[l][c])
		{
			if (game->st_map->map[l][c] == 'P')
			{
				game->st_player.x = c;
				game->st_player.y = l;
			}
			c++;
		}
		l++;
	}
	game->st_player.nb_move = 0;
	if (game->st_player.x == 0 && game->st_player.y == 0)
		close_window(game, 1, "Error\ninvalid map\n", EXIT_FAILURE);
}
