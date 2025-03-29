/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/29 14:30:49 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <complex.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	print_map(t_game *game)
{
	size_t	l;

	l = 0;
	while (game->st_map->map[l])
	{
		ft_printf("%s\n", game->st_map->map[l]);
		l++;
	}
	ft_printf("path : %s\n", game->st_map->path);
	ft_printf("size l : %i\n", game->st_map->size_l);
	ft_printf("size c : %i\n", game->st_map->size_c);
	ft_printf("item : %i\n", game->st_map->nb_item);
	ft_printf("exit : %i\n", game->st_map->nb_exit);
	ft_printf("player : %i\n", game->st_map->nb_player);

	ft_printf("----player----\n");
	ft_printf("x : %i\n", game->st_player->x);
	ft_printf("y : %i\n", game->st_player->y);
}

void	draw(t_game *game, void	*mlx_ptr, void	*win)
{
	int sx;
	int sy;
	(void)win;
	void *img_wall;
	img_wall = mlx_xpm_file_to_image(mlx_ptr, "assets/wall_up.xpm", &sx, &sy);
	void *img_floor;
	img_floor = mlx_xpm_file_to_image(mlx_ptr, "assets/floor.xpm", &sx, &sy);
	size_t	l;
	size_t	c;

	l = 0;
	while (game->st_map->map[l])
	{
		c = 0;
		while (game->st_map->map[l][c])
		{
			if (is_wall(game->st_map, l, c) == 1)
				mlx_put_image_to_window(mlx_ptr, win, img_wall, c * 128 , l * 128);
			if (is_wall(game->st_map, l, c) == 2)
				mlx_put_image_to_window(mlx_ptr, win, img_floor, c * 128 , l * 128);
			c++;
		}
		l++;
	}
}

int end()
{
	int *i;

	i = 0;
	return(0);
}

void	init_game(t_game *game, char **argv)
{
	game->st_map = pars(argv[1]);
	init_info(game, game->st_map, 1);
	if (check_map(game) == 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	init_mlx(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	(void)argc;
	init_game(game, argv);
	mlx_loop(game->st_mlx->mlx_ptr);
	free_game(game);
	return (EXIT_SUCCESS);
}
