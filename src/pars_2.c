/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:52 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/24 14:23:36 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_texture_id(t_map *st_map)
{
	st_map->id_wall[0] = '1';
	st_map->id_wall[1] = '2';
	st_map->id_wall[2] = '\0';
	st_map->id_floor[0] = '0';
	st_map->id_floor[1] = '\0';
}

int	is_wall(t_map *st_map, size_t l, size_t c)
{
	size_t	i;

	i = 0;
	while (st_map->id_wall[i])
	{
		if (st_map->map[l][c] == st_map->id_wall[i])
			return (1);
		i++;
	}
	i = 0;
	while (st_map->id_floor[i])
	{
		if (st_map->map[l][c] == st_map->id_floor[i])
			return (2);
		i++;
	}
	return (0);
}

int	check_wall_up_down()
{
	return (1);
}
