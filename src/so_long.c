/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/03 18:42:49 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <complex.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>

void	init_game(t_game *game, char **argv)
{
	game->st_map = NULL;
	game->st_mlx = NULL;
	game->st_item = NULL;
	game->st_map = pars(game, argv[1]);
	init_info(game, game->st_map, 1);
	if (check_map(game) == 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	init_mlx(game);
}

int	close_win(t_game *game)
{
	if (game->st_mlx)
		mlx_loop_end(game->st_mlx->mlx_ptr);
	free_game(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	lisen_key(t_game *game)
{
	mlx_hook(game->st_mlx->win_ptr, 2, (1L << 0), keypresse, game);
	mlx_hook(game->st_mlx->win_ptr, DestroyNotify,
		KeyPressMask, close_win, game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	(void)argc;
	(void)argv;
	init_game(game, argv);
	draw(game);
	lisen_key(game);
	mlx_loop(game->st_mlx->mlx_ptr);
	return (EXIT_SUCCESS);
}
