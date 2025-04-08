/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:50:00 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/08 16:05:52 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/so_long.h"
#include "../minilibx-linux/mlx.h"

void	free_img(t_game *game)
{
	if (game->st_mlx->img_f_1)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->img_f_1);
	if (game->st_mlx->img_f_2)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->img_f_2);
	if (game->st_mlx->img_b)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->img_b);
	if (game->st_mlx->img_w)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->img_w);
	if (game->st_mlx->img_w_1)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->img_w_1);
	if (game->st_mlx->img_w_2)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->img_w_2);
	if (game->st_mlx->exit_close)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->exit_close);
	if (game->st_mlx->exit_open)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->exit_open);
	if (game->st_mlx->mushroom)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->mushroom);
	if (game->st_mlx->img_wizard)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->img_wizard);
	if (game->st_mlx->gandalf)
		mlx_destroy_image(game->st_mlx->mlx_ptr, game->st_mlx->gandalf);
}

void	free_mlx(t_game *game)
{
	if (game->st_mlx->mlx_ptr)
		free_img(game);
	if (game->st_mlx->win_ptr)
		mlx_destroy_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr);
	if (game->st_mlx->mlx_ptr)
	{
		mlx_destroy_display(game->st_mlx->mlx_ptr);
		free(game->st_mlx->mlx_ptr);
	}
	free(game->st_mlx);
}

void	free_item(t_game *game)
{
	t_item	*tmp;

	while (game->st_item)
	{
		tmp = game->st_item->next;
		free(game->st_item);
		game->st_item = tmp;
	}
	tmp = NULL;
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->st_map)
			free_map(game->st_map);
		if (game->st_mlx)
			free_mlx(game);
		if (game->st_item)
			free_item(game);
		free(game);
	}
}
