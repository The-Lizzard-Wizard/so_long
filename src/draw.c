/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:38:14 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/04 16:53:34 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <complex.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>

void	draw_wall(t_game *game, size_t l, size_t c)
{
	if (game->st_map->map[l][c] == '1')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_w_1, c * 128, l * 128);
	if (game->st_map->map[l][c] == 'B')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_b, c * 128, l * 128);
	if (game->st_map->map[l][c] == 'W')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_w, c * 128, l * 128);
	if (game->st_map->map[l][c] == '2')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_w_2, c * 128, l * 128);
}

void	draw_floor(t_game *game, size_t l, size_t c)
{
	if (game->st_map->map[l][c] == '0')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_f_1, c * 128, l * 128);
	if (game->st_map->map[l][c] == 'P')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_f_1, c * 128, l * 128);
	if (game->st_map->map[l][c] == 'C')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_f_1, c * 128, l * 128);
	if (game->st_map->map[l][c] == '3')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr,
			game->st_mlx->win_ptr, game->st_mlx->img_f_2, c * 128, l * 128);
	if (game->st_map->map[l][c] == 'E')
	{
		if (game->st_player.mushroom == game->st_map->nb_item)
			mlx_put_image_to_window(game->st_mlx->mlx_ptr,
				game->st_mlx->win_ptr,
				game->st_mlx->exit_open, c * 128, l * 128);
		else
			mlx_put_image_to_window(game->st_mlx->mlx_ptr,
				game->st_mlx->win_ptr,
				game->st_mlx->exit_close, c * 128, l * 128);
	}
}

void	draw_map(t_game *game)
{
	size_t	l;
	size_t	c;

	l = 0;
	while (game->st_map->map[l])
	{
		c = 0;
		while (game->st_map->map[l][c])
		{
			draw_wall(game, l, c);
			draw_floor(game, l, c);
			c++;
		}
		l++;
	}
}

void	draw_item(t_game *game)
{
	t_item	*item;
	int		i;

	i = 0;
	item = game->st_item;
	while (i < game->st_map->nb_item)
	{
		if (item->collect == 0)
			mlx_put_image_to_window(game->st_mlx->mlx_ptr,
				game->st_mlx->win_ptr, game->st_mlx->mushroom,
				item->x * 128, item->y * 128);
		item = item->next;
		i++;
	}
}

void	draw(t_game *game)
{
	draw_map(game);
	draw_item(game);
	mlx_put_image_to_window(game->st_mlx->mlx_ptr,
		game->st_mlx->win_ptr, game->st_mlx->img_wizard,
		game->st_player.x * 128, game->st_player.y * 128);
}
