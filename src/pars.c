/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:54:29 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/21 16:29:56 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include "../libft/libft.h"

char	**pars(char **argv)
{
	int		ber;
	char	**map;
	char	*line;
	char	*map_line;

	line = NULL;
	map_line = ft_strdup("");
	ber = open(argv[1], O_RDONLY);
	if (ber == -1)
		return (NULL);
	line = get_next_line(ber);
	while (line)
	{
		map_line = ft_strjoin(map_line, line);
		free(line);
		line = get_next_line(ber);
	}
	map = ft_split(map_line, '\n');
	return (map);
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
