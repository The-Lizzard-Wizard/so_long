/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gandalf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:03:04 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/08 16:00:30 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/libft.h"
#include <unistd.h>

int	is_gandalf(t_map *st_map, size_t l, size_t c)
{
    if (st_map->map[l][c] == 'G')
    {
        return (1);
    }
	return (0);
}

void	check_gandalf(t_game *game, int key)
{
	if (key == 119)
		if (is_gandalf(game->st_map, game->st_player.y - 1,
				game->st_player.x) == 1)
			ft_printf("you shall not pass !!\n");
	if (key == 100)
		if (is_gandalf(game->st_map, game->st_player.y,
				game->st_player.x + 1) == 1)
            ft_printf("you shall not pass !!\n");
	if (key == 115)
		if (is_gandalf(game->st_map, game->st_player.y + 1,
				game->st_player.x) == 1)
            ft_printf("you shall not pass !!\n");
	if (key == 97)
		if (is_gandalf(game->st_map, game->st_player.y,
				game->st_player.x - 1) == 1)
            ft_printf("you shall not pass !!\n");
}