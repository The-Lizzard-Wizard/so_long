/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/25 15:50:26 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
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
	ft_printf("size l : %i\n", game->st_map->size_l);
	ft_printf("size c : %i\n", game->st_map->size_c);
	ft_printf("item : %i\n", game->st_map->nb_item);
	ft_printf("exit : %i\n", game->st_map->nb_exit);
	ft_printf("player : %i\n", game->st_map->nb_player);
}

int	main(int argc, char **argv)
{
	t_game	*game;


	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	(void)argc;
	game->st_map = pars(argv);
	init_info(game);
	if (check_map(game) == 0)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	print_map(game);
	return (EXIT_SUCCESS);
}
