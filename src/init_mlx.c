/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:50:36 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/09 16:53:48 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

void	load_img(t_game *game)
{
	int	sx;
	int	sy;

	game->st_mlx->img_f_1 = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/floor.xpm", &sx, &sy);
	game->st_mlx->img_f_2 = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/floor2.xpm", &sx, &sy);
	game->st_mlx->img_w_1 = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/wall_up.xpm", &sx, &sy);
	game->st_mlx->img_w_2 = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/wall_face.xpm", &sx, &sy);
	game->st_mlx->img_b = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/bush.xpm", &sx, &sy);
	game->st_mlx->img_w = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/water.xpm", &sx, &sy);
	game->st_mlx->exit_close = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/exit_close.xpm", &sx, &sy);
	game->st_mlx->exit_open = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/exit_open.xpm", &sx, &sy);
	game->st_mlx->mushroom = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/mushroom.xpm", &sx, &sy);
	game->st_mlx->img_wizard = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/player.xpm", &sx, &sy);
}

void	check_img(t_game *game)
{
	if (!game->st_mlx->img_f_1)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->img_f_2)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->img_w_1)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->img_w_2)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->img_b)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->img_w)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->exit_close)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->exit_open)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->mushroom)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
	if (!game->st_mlx->img_wizard)
		close_window(game, 1, "Error\nimage load failed\n", EXIT_FAILURE);
}

void	init_img(t_game *game)
{
	load_img(game);
	load_img2(game);
	check_img(game);
	check_img2(game);
}

void	init_mlx(t_game *game)
{
	game->st_mlx = malloc(sizeof(t_mlx));
	if (!game->st_mlx)
		close_window(game, 1, "Error\nmlx load failed\n", EXIT_FAILURE);
	game->st_mlx->mlx_ptr = NULL;
	game->st_mlx->win_ptr = NULL;
	game->st_mlx->mlx_ptr = mlx_init();
	if (!game->st_mlx->mlx_ptr)
		close_window(game, 1, "Error\nmlx load failed\n", EXIT_FAILURE);
	game->st_mlx->img_f_1 = NULL;
	game->st_mlx->img_f_2 = NULL;
	game->st_mlx->img_w_1 = NULL;
	game->st_mlx->img_w_2 = NULL;
	game->st_mlx->img_b = NULL;
	game->st_mlx->img_w = NULL;
	game->st_mlx->exit_close = NULL;
	game->st_mlx->exit_open = NULL;
	game->st_mlx->mushroom = NULL;
	game->st_mlx->img_wizard = NULL;
	init_img(game);
	game->st_mlx->win_ptr = mlx_new_window(game->st_mlx->mlx_ptr,
			game->st_map->size_c * 128,
			game->st_map->size_l * 128, "so_long");
	if (!game->st_mlx->win_ptr)
		close_window(game, 1, "Error\nmlx win load failed\n", EXIT_FAILURE);
}
