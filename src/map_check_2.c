/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:51:34 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/17 15:27:08 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../libft/libft.h"

void	init_index_null(t_map *st_map)
{
	st_map->id_floor = NULL;
	st_map->id_wall = NULL;
}

int	check_invalid_texture(t_game *game)
{
	size_t	l;
	size_t	c;
	int		i;

	l = 0;
	i = 0;
	while (game->st_map->map[l])
	{
		c = 0;
		while (game->st_map->map[l][c])
		{
			i = 0;
			if (ft_strchr(game->st_map->id_wall,
					game->st_map->map[l][c]) != NULL)
				i++;
			if (ft_strchr(game->st_map->id_floor,
					game->st_map->map[l][c]) != NULL)
				i++;
			c++;
			if (i == 0)
				return (0);
		}
		l++;
	}
	return (1);
}
