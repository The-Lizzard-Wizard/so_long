/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:48:51 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/08 14:49:39 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../minilibx-linux/mlx.h"

void	load_img2(t_game *game)
{
	int	sx;
	int	sy;

	game->st_mlx->gandalf = mlx_xpm_file_to_image(game->st_mlx->mlx_ptr,
			"assets/gandalf.xpm", &sx, &sy);
}

void	check_img2(t_game *game)
{
	if (!game->st_mlx->gandalf)
		close_window(game, 1, "Error\ngandalf load failed\n");
}