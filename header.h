/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:42:18 by albaud            #+#    #+#             */
/*   Updated: 2024/01/04 02:50:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "srcs/sources.h"

typedef struct s_board
{
	t_window	w;
	t_canvas	croix;
	t_canvas	rond;
	t_canvas	board_img;
	t_vector	pos[9];
	t_matrix	board;
	int			moves;
	t_vector	players;
	t_canvas	butons[20];
	t_canvas	screens[5];
	int			xwin;
	int			owin;

}	t_board;

void		reset(int key, t_board *game);
void		init_screens(t_board *game);
void		init_buttons(t_board *game);
int			win(int **map, int num);
int			tie(int **map);
int			play_as(t_board *game, int piece, int pos, int key);
int			check_win(t_board *game);
int			randbot(t_board game);
int			minmax(t_board board, int piece);
int			play_bots(t_board *game);
void		ft_putimg(t_window w, void *img, t_vector pos);
#endif
