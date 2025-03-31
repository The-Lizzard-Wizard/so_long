/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/31 14:26:26 by gchauvet         ###   ########.fr       */
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

void	draw_wall(t_game *game, size_t l,size_t c)
{
	if (game->st_map->map[l][c] == '1')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_w_1, c * 128 , l * 128);
	if (game->st_map->map[l][c] == 'B')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_b, c * 128 , l * 128);
	if (game->st_map->map[l][c] == 'W')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_w, c * 128 , l * 128);
	if (game->st_map->map[l][c] == '2')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_w_2, c * 128 , l * 128);
}

void	draw_floor(t_game *game, size_t l,size_t c)
{
	if (game->st_map->map[l][c] == '0')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_f_1, c * 128 , l * 128);
	if (game->st_map->map[l][c] == 'P')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_f_1, c * 128 , l * 128);
	if (game->st_map->map[l][c] == 'C')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_f_1, c * 128 , l * 128);
	if (game->st_map->map[l][c] == '3')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->img_f_2, c * 128 , l * 128);
	if (game->st_map->map[l][c] == 'E')
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->exit_close, c * 128 , l * 128);
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

	item = game->st_item;
	while (item)
	{
		mlx_put_image_to_window(game->st_mlx->mlx_ptr, game->st_mlx->win_ptr, game->st_mlx->mushroom, item->x * 128 , item->y * 128);
		item = item->next;
	}
}

void	draw(t_game *game)
{
	draw_map(game);
	draw_item(game);
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
	draw(game);
	mlx_loop(game->st_mlx->mlx_ptr);
	free_game(game);
	return (EXIT_SUCCESS);
}
