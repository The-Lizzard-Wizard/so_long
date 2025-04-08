/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:51:41 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/08 13:13:10 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_map *st_map)
{
	free_array(st_map->map);
	free(st_map->path);
	free(st_map->id_wall);
	free(st_map->id_floor);
	free(st_map);
}

void	check_map_info(t_game *game, t_map *st_map)
{
	if (!st_map->path)
		close_window(game, 0, NULL);
	if (!st_map->map)
	{
		free(st_map->path);
		free(st_map);
		close_window(game, 1, "Error\nthe map is empty\n");
	}
	init_index_null(st_map);
}
