/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/26 15:56:06 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <complex.h>
#include <stdlib.h>
#include "../libft/libft.h"

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

int	main(int argc, char **argv)
{
	t_game	*game;


	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	(void)argc;
	game->st_map = pars(argv[1]);
	init_info(game, game->st_map, 1);
	if (check_map(game) == 0)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	print_map(game);
	free_game(game);
	return (EXIT_SUCCESS);
}
