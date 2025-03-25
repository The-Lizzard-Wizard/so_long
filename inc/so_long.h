/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:24:45 by gchauvet          #+#    #+#             */
/*   Updated: 2025/03/25 15:55:00 by gchauvet         ###   ########.fr       */
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
	int				nb_exit;
	int				nb_player;
	int				nb_item;
}	t_map;

typedef struct s_item
{
	size_t			x;
	size_t			y;
	struct s_item  *next;
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
	t_item			*st_item;
}	t_game;

t_map	*pars(char **argv);
void	print_map(t_game *game);
int		check_map(t_game *game);
int		check_size(t_game *game);
void	init_texture_id(t_game *game);
int		is_wall(t_game *game, size_t l, size_t c);
int		check_wall(t_game *game);
void	init_info(t_map *st_map);

#endif