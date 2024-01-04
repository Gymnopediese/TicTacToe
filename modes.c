/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:40:37 by albaud            #+#    #+#             */
/*   Updated: 2024/01/04 02:53:31 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	play(t_board *game, int x, int y, int boy)
{
	t_vector	place;

	place = game->pos[y * 3 + x];
	if (game->board.map[y][x] != 0)
		return (0);
	if (boy == 0)
	{
		ft_putimg(game->w, game->croix.img, place);
		game->board.map[y][x] = -1;
	}
	else if (boy == 1)
	{
		ft_putimg(game->w, game->rond.img, place);
		game->board.map[y][x] = 1;
	}
	game->moves++;
	return (0);
}

void	play_as_bot(t_board *game, int boy)
{
	int	rand;

	if (boy == 0)
		boy = -1;
	if (game->moves == 0)
		rand = 4;
	else
		rand = minmax(*game, boy);
	if (boy == -1)
		boy = 0;
	play(game, (int)rand % 3, (int)rand / 3, boy);
}

void	play_as_random(t_board *game, int boy)
{
	int	rand;

	if (boy == 0)
		boy = -1;
	if (game->moves == 0)
		rand = 4;
	else
		rand = randbot(*game);
	if (boy == -1)
		boy = 0;
	play(game, (int)rand % 3, (int)rand / 3, boy);
}

int	play_as(t_board *game, int piece, int pos, int key)
{
	if (check_win(game))
		return (1);
	if (key == 0)
		play(game, (int)pos % 3, (int)pos / 3, piece);
	if (key == 1)
		play_as_bot(game, piece);
	if (key == 2)
		play_as_random(game, piece);
	ft_putimg(game->w, game->screens[piece + 3].img, ft_vect(500, 0, 0));
	return (0);
}

int	ft_vectind(t_vector v, int ind)
{
	if (ind == 0)
		return (v.x);
	if (ind == 1)
		return (v.y);
	if (ind == 2)
		return (v.z);
	return (0);
}

int	play_bots(t_board *game)
{
	while (ft_vectind(game->players, game->moves % 2) != 0)
	{
		if (play_as(game, game->moves % 2, 0,
				ft_vectind(game->players, game->moves % 2)))
			return (1);
	}
	return (0);
}
