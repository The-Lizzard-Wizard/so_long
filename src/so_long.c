/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:12:53 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/22 17:31:08 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include "../libft/libft.h"

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
