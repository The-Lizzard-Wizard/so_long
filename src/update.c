/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:57:01 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/05 14:24:35 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/libft.h"
#include <unistd.h>

void	check_item(t_game *game)
{
	t_item	*tmp;

	tmp = game->st_item;
	while (tmp)
	{
		if (tmp->collect == 0 && tmp->x == game->st_player.x
			&& tmp->y == game->st_player.y)
		{
			game->st_player.mushroom++;
			tmp->collect = 1;
		}
		tmp = tmp->next;
	}
}

void	check_move(t_game *game, int key)
{
	if (key == 119)
		if (is_wall(game->st_map, game->st_player.y - 1,
				game->st_player.x) == 2)
			game->st_player.y--;
	if (key == 100)
		if (is_wall(game->st_map, game->st_player.y,
				game->st_player.x + 1) == 2)
			game->st_player.x++;
	if (key == 115)
		if (is_wall(game->st_map, game->st_player.y + 1,
				game->st_player.x) == 2)
			game->st_player.y++;
	if (key == 97)
		if (is_wall(game->st_map, game->st_player.y,
				game->st_player.x - 1) == 2)
			game->st_player.x--;
}

void	move_cunter(t_game *game, int key)
{
	static int c;

	if (key == 119)
		if (is_wall(game->st_map, game->st_player.y - 1,
				game->st_player.x) == 2)
			c++;
	if (key == 100)
		if (is_wall(game->st_map, game->st_player.y,
				game->st_player.x + 1) == 2)
			c++;
	if (key == 115)
		if (is_wall(game->st_map, game->st_player.y + 1,
				game->st_player.x) == 2)
			c++;;
	if (key == 97)
		if (is_wall(game->st_map, game->st_player.y,
				game->st_player.x - 1) == 2)
			c++;
	ft_printf("moves : %i\n", c);
}

int	keypresse(int key, t_game *game)
{
	check_move(game, key);
	move_cunter(game, key);
	check_item(game);
	if (game->st_player.mushroom == game->st_map->nb_item
			&& game->st_map->exit_x == game->st_player.x
			&& game->st_map->exit_y == game->st_player.y)
		close_window(game, 1, "you win !!\n");
	if (key == 119 || key == 100 || key == 115 || key == 97)
		draw(game);
	if (key == 65307)
		close_window(game, 0, NULL);
	return (0);
}
