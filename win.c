/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:53:24 by albaud            #+#    #+#             */
/*   Updated: 2024/01/04 02:49:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	win(int **map, int num)
{
	if (map[0][0] + map[0][1] + map[0][2] == num)
		return (1);
	if (map[1][0] + map[1][1] + map[1][2] == num)
		return (1);
	if (map[2][0] + map[2][1] + map[2][2] == num)
		return (1);
	if (map[0][0] + map[1][0] + map[2][0] == num)
		return (1);
	if (map[0][1] + map[1][1] + map[2][1] == num)
		return (1);
	if (map[0][2] + map[1][2] + map[2][2] == num)
		return (1);
	if (map[0][0] + map[1][1] + map[2][2] == num)
		return (1);
	if (map[0][2] + map[1][1] + map[2][0] == num)
		return (1);
	return (0);
}

int	tie(int **map)
{
	if (map[0][0] && map[0][1] && map[0][2] &&
		map[1][0] && map[1][1] && map[1][2] &&
		map[2][0] && map[2][1] && map[2][2] &&
			!win(map, 3) && !win(map, -3))
		return (1);
	return (0);
}

void	ft_putimg(t_window w, void *img, t_vector pos)
{
	mlx_put_image_to_window(w.mlx, w.win, img, pos.x, pos.y);
}

int	check_win(t_board *game)
{
	int	**map;

	map = game->board.map;
	if (win(map, 3))
	{
		ft_putimg(game->w, game->screens[1].img, ft_vect(500, 0, 0));
		game->owin++;
		return (1);
	}
	if (win(map, -3))
	{
		ft_putimg(game->w, game->screens[0].img, ft_vect(500, 0, 0));
		game->xwin++;
		return (1);
	}
	if (tie(map))
	{
		ft_putimg(game->w, game->screens[2].img, ft_vect(500, 0, 0));
		return (1);
	}
	return (0);
}
