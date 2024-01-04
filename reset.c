/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:21:26 by albaud            #+#    #+#             */
/*   Updated: 2024/01/04 02:50:32 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_buttons(int key, t_board *game)
{
	int	i;

	i = -1;
	while (++i < 9)
		ft_putimg(game->w, game->butons[i].img, ft_vect(i * 100, 500, 0));
	if (key == KEYCODE_1)
		ft_putimg(game->w, game->butons[9].img, ft_vect(0, 500, 0));
	else if (key == KEYCODE_2)
		ft_putimg(game->w, game->butons[10].img, ft_vect(1 * 100, 500, 0));
	else if (key == KEYCODE_3)
		ft_putimg(game->w, game->butons[11].img, ft_vect(2 * 100, 500, 0));
	else if (key == KEYCODE_4)
		ft_putimg(game->w, game->butons[12].img, ft_vect(3 * 100, 500, 0));
	else if (key == KEYCODE_5)
		ft_putimg(game->w, game->butons[13].img, ft_vect(4 * 100, 500, 0));
	else if (key == KEYCODE_6)
		ft_putimg(game->w, game->butons[14].img, ft_vect(5 * 100, 500, 0));
	else if (key == KEYCODE_7)
		ft_putimg(game->w, game->butons[15].img, ft_vect(6 * 100, 500, 0));
	else if (key == KEYCODE_8)
		ft_putimg(game->w, game->butons[16].img, ft_vect(7 * 100, 500, 0));
	else if (key == KEYCODE_9)
		ft_putimg(game->w, game->butons[17].img, ft_vect(8 * 100, 500, 0));
	ft_putimg(game->w, game->butons[18].img, ft_vect(9 * 100, 500, 0));
	ft_putimg(game->w, game->butons[19].img, ft_vect(10 * 100, 500, 0));
}

int	set_players(int key, t_board *game)
{
	if (key == KEYCODE_1)
		game->players = ft_vect(0, 1, 0);
	else if (key == KEYCODE_2)
		game->players = ft_vect(1, 0, 0);
	else if (key == KEYCODE_3)
		game->players = ft_vect(0, 2, 0);
	else if (key == KEYCODE_4)
		game->players = ft_vect(2, 0, 0);
	else if (key == KEYCODE_5)
		game->players = ft_vect(1, 2, 0);
	else if (key == KEYCODE_6)
		game->players = ft_vect(2, 1, 0);
	else if (key == KEYCODE_7)
		game->players = ft_vect(1, 1, 0);
	else if (key == KEYCODE_8)
		game->players = ft_vect(2, 2, 0);
	else if (key == KEYCODE_9)
		game->players = ft_vect(0, 0, 0);
	else
		return (1);
	return (0);
}

void	ft_reset_intm(t_matrix m, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m.size.x)
	{
		j = -1;
		while (++j < m.size.y)
			m.map[i][j] = n;
	}
}

void	reset(int key, t_board *game)
{
	if (set_players(key, game))
		return ;
	set_buttons(key, game);
	ft_reset_intm(game->board, 0);
	mlx_put_image_to_window(game->w.mlx, game->w.win,
		game->board_img.img, 0, 0);
	ft_putimg(game->w, game->screens[0].img, ft_vect(500, 0, 0));
	mlx_string_put(game->w.mlx, game->w.win, 945, 508, WHITE,
		ft_itoa(game->xwin));
	mlx_string_put(game->w.mlx, game->w.win, 1045, 508, WHITE,
		ft_itoa(game->owin));
	game->moves = 0;
}
