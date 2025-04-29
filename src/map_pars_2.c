/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:54:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/29 17:33:55 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../inc/so_long.h"

int	check_map_line(char *map_line)
{
	if (!map_line)
		return (0);
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)))
		return (1);
	if (map_line[0] == '\n' || map_line[ft_strlen(map_line) - 1] == '\n')
		return (1);
	return (0);
}

t_map	*malloc_map(t_game *game, int map_fd, char *line, char *map_line)
{
	t_map	*st_map;

	st_map = malloc(sizeof(t_map));
	if (!st_map)
	{
		close(map_fd);
		free(line);
		free(map_line);
		close_window(game, 1, "Error\nmap alloc failed\n", EXIT_FAILURE);
	}
	if (check_map_line(map_line))
	{
		free(st_map);
		free(line);
		free(map_line);
		close(map_fd);
		close_window(game, 1, "Error\ninvalid map\n", EXIT_FAILURE);
	}
	st_map->map = ft_split(map_line, '\n');
	return (st_map);
}

void	check_map_info(t_game *game, t_map *st_map)
{
	if (!st_map->map && !st_map->path)
	{
		free(st_map->path);
		free(st_map);
		close_window(game, 1, "Error\nmap info alloc failed\n", EXIT_FAILURE);
	}
	if (!st_map->path)
	{
		free_array(st_map->map);
		free(st_map);
		close_window(game, 1, "Error\nmap info alloc failed\n", EXIT_FAILURE);
	}
	if (!st_map->map)
	{
		free(st_map->path);
		free(st_map);
		close_window(game, 1, "Error\nthe map is empty\n", EXIT_FAILURE);
	}
	init_index_null(st_map);
}
