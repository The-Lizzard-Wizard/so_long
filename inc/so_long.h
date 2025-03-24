/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:24:45 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/24 17:06:44 by gchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>

typedef struct s_map
{
	char			**map;
	size_t			size_l;
	size_t			size_c;
	char			id_wall[3];
	char			id_floor[2];
}	t_map;

typedef struct s_game
{
	t_map			*st_map;
}	t_game;

t_map	*pars(char **argv);
void	print_map(t_game *game);
int		check_map(t_game *game);
int		check_size(t_game *game);
void	init_texture_id(t_game *game);
int		is_wall(t_game *game, size_t l, size_t c);
int		check_wall(t_game *game);

#endif