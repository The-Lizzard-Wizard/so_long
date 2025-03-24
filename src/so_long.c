/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/24 13:02:57 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include "../libft/libft.h"

void	print_map(t_map *st_map)
{
	size_t	l;

	l = 0;
	while (st_map->map[l])
	{
		ft_printf("%s\n", st_map->map[l]);
		l++;
	}
	ft_printf("size l : %i\n", st_map->size_l);
	ft_printf("size c : %i\n", st_map->size_c);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	(void)argc;
	map = pars(argv);
	if (check_map(map) == 0)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	print_map(map);
	return (EXIT_SUCCESS);
}
