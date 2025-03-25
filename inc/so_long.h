/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gaelchauvet@orange.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:24:45 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/25 02:08:23 by gchauvet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>
//push pls
typedef struct s_map
{
	char			**map;
	size_t			size_l;
	size_t			size_c;
	char			id_wall[3];
	char			id_floor[2];
}	t_map;

typedef struct s_item
{
	size_t			x;
	size_t			y;
	s_item struct *next;
}	t_item;

typedef struct s_player
{
	size_t			x;
	size_t			y;
}	t_player;

typedef struct s_game
{
	t_map			*st_map;
	t_player		*st_player;
	t_iem			*st_iem;
}	t_game;

t_map	*pars(char **argv);
void	print_map(t_game *game);
int		check_map(t_game *game);
int		check_size(t_game *game);
void	init_texture_id(t_game *game);
int		is_wall(t_game *game, size_t l, size_t c);
int		check_wall(t_game *game);

#endif