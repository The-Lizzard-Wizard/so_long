/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvet <gchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:24:45 by gchauvet          #+#    #+#             */
/*   Updated: 2025/04/03 18:09:35 by gchauvet         ###   ########.fr       */
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
	char 			*path;
	char			*id_wall;
	char			*id_floor;
	int				nb_exit;
	int				nb_player;
	int				nb_item;
	size_t			exit_x;
	size_t			exit_y;
}	t_map;

typedef struct s_item
{
	size_t			x;
	size_t			y;
	int				collect;
	struct s_item  *next;
}	t_item;

typedef struct s_player
{
	size_t			x;
	size_t			y;
	int				mushroom;
}	t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_f_1;
	void	*img_f_2;
	void	*img_b;
	void	*img_w;
	void	*img_w_1;
	void	*img_w_2;
	void	*exit_close;
	void	*exit_open;
	void	*mushroom;
	void	*img_wizard;
} t_mlx;

typedef struct s_game
{
	t_map			*st_map;
	t_player		st_player;
	t_mlx			*st_mlx;
	t_item			*st_item;
}	t_game;

void	print_map(t_game *game);
int		is_wall(t_map *st_map, size_t l, size_t c);
int		check_map(t_game *game);
int		check_size(t_game *game);
int		check_wall(t_game *game);

t_map	*pars(t_game *game, char *path);
void	init_texture_id(t_game *game, t_map *st_map);
void	init_player(t_game *game);
void	init_info(t_game *game, t_map *st_map, int initp);
void	init_mlx(t_game *game);

void	free_array(char **array);
void	free_map(t_map *st_map);
void	free_game(t_game *game);

t_item	*new_item(t_game *game);
t_item	*add_item(t_game *game, t_map *st_map, size_t x, size_t y);

int		player_move_up(t_game *game);
int		keypresse(int key, t_game *game);
void	draw(t_game *game);
void	draw_wall(t_game *game, size_t l,size_t c);
void	draw_floor(t_game *game, size_t l,size_t c);
void	draw_map(t_game *game);
void	draw_item(t_game *game);
int		close_win(t_game *game);

#endif