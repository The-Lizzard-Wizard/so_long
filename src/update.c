/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:57:01 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/03 18:31:17 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/libft.h"
#include <unistd.h>

int	player_move_up(t_game *game)
{
	if (is_wall(game->st_map, game->st_player.y - 1, game->st_player.x) == 2)
		game->st_player.y--;
	return (0);
}

void	check_item(t_game *game)
{
	t_item *tmp;

	tmp = game->st_item;
	while (tmp)
	{
		if (tmp->collect == 0 && tmp->x == game->st_player.x && tmp->y == game->st_player.y)
		{
			game->st_player.mushroom++;
			tmp->collect = 1;
		}
		tmp = tmp->next;
	}
}

int keypresse(int key, t_game *game)
{
	ft_printf("%i\n", key);
	if (key == 119)
		if (is_wall(game->st_map, game->st_player.y - 1, game->st_player.x) == 2)
			game->st_player.y--;
	if (key == 100)
		if (is_wall(game->st_map, game->st_player.y, game->st_player.x + 1) == 2)
			game->st_player.x++;
	if (key == 115)
		if (is_wall(game->st_map, game->st_player.y + 1, game->st_player.x) == 2)
			game->st_player.y++;
	if (key == 97)
		if (is_wall(game->st_map, game->st_player.y, game->st_player.x - 1) == 2)
			game->st_player.x--;
	check_item(game);
	if (game->st_player.mushroom == game->st_map->nb_item &&
			game->st_map->exit_x == game->st_player.x &&
				game->st_map->exit_y == game->st_player.y)
	{
			ft_printf("you win !!\n");
			close_win(game);
	}
	draw(game);
	return (0);
}
