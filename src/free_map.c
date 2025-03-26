/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:48:58 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/26 16:09:32 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/so_long.h"

void	free_map(t_map *st_map)
{
	free_array(st_map->map);
	free(st_map->path);
	free(st_map->id_wall);
	free(st_map->id_floor);
	free(st_map);
}