/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/09 16:37:55 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/libft.h"
#include <complex.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>

int	check_extansion(char *path)
{
	size_t	i;

	i = 0;
	while (i <= 3)
	{
		if (i == 0 && path[ft_strlen(path - i)] != 'r')
			return (0);
		if (i == 1 && path[ft_strlen(path - i)] != 'e')
			return (0);
		if (i == 2 && path[ft_strlen(path - i)] != 'b')
			return (0);
		if (i == 3 && path[ft_strlen(path - i)] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	init_game(t_game *game, char **argv)
{
	game->st_map = NULL;
	game->st_mlx = NULL;
	game->st_item = NULL;
	game->st_map = pars(game, argv[1]);
	init_info(game, game->st_map, 1);
	if (check_map(game) == 0)
		close_window(game, 1, "Error\ninvalid map\n", EXIT_FAILURE);
	init_mlx(game);
}

int	close_window(t_game *game, int aff_ms, char *ms, int fd)
{
	if (aff_ms == 1 && ms)
		ft_printf("%s", ms);
	if (game)
	{
		if (game->st_mlx && game->st_mlx->mlx_ptr)
			mlx_loop_end(game->st_mlx->mlx_ptr);
		free_game(game);
	}
	exit(fd);
	return (fd);
}

void	lisen_key(t_game *game)
{
	mlx_hook(game->st_mlx->win_ptr, 2, (1L << 0), keypresse, game);
	mlx_hook(game->st_mlx->win_ptr, DestroyNotify,
		KeyPressMask, close_window, game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		close_window(game, 1,
			"Error\nbad arguments\n", EXIT_FAILURE);
	if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		close_window(game, 1, "Error\nbad extention\n", EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	if (!game)
		close_window(game, 1, "Error\ngame alloc failed\n", EXIT_FAILURE);
	init_game(game, argv);
	draw(game);
	lisen_key(game);
	mlx_loop(game->st_mlx->mlx_ptr);
	return (EXIT_SUCCESS);
}
