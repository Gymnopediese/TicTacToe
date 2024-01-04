/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tictactoe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:53:24 by albaud            #+#    #+#             */
/*   Updated: 2024/01/04 02:51:44 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_positions(t_board *game)
{
	game->pos[0] = ft_vect(17, 16, 0);
	game->pos[1] = ft_vect(177, 16, 0);
	game->pos[2] = ft_vect(337, 16, 0);
	game->pos[3] = ft_vect(17, 177, 0);
	game->pos[4] = ft_vect(177, 177, 0);
	game->pos[5] = ft_vect(337, 177, 0);
	game->pos[6] = ft_vect(17, 337, 0);
	game->pos[7] = ft_vect(177, 337, 0);
	game->pos[8] = ft_vect(337, 337, 0);
}

int	ft_place(int key)
{
	if (key == KEYCODE_Q)
		return (0);
	if (key == KEYCODE_W)
		return (1);
	if (key == KEYCODE_E)
		return (2);
	if (key == KEYCODE_A)
		return (3);
	if (key == KEYCODE_S)
		return (4);
	if (key == KEYCODE_D)
		return (5);
	if (key == KEYCODE_Y)
		return (6);
	if (key == KEYCODE_X)
		return (7);
	if (key == KEYCODE_C)
		return (8);
	return (-1);
}

int	play_hook(int key, t_board *game)
{
	int			ind;

	ind = ft_place(key);
	reset(key, game);
	if (play_bots(game))
		return (0);
	if (ind >= 0 && play_as(game, game->moves % 2, ind, 0))
		return (0);
	if (play_bots(game))
		return (0);
	check_win(game);
	return (0);
}

int	main(void)
{
	t_board		game;

	ft_mlx_init(&game.w, 1095, 537, "tictactoe");
	game.board_img = ft_init_image(game.w.mlx, "sprites/board.xpm");
	game.rond = ft_init_image(game.w.mlx, "sprites/rond.xpm");
	game.croix = ft_init_image(game.w.mlx, "sprites/croix.xpm");
	game.board = ft_init_intm(3, 3, 0);
	init_screens(&game);
	init_buttons(&game);
	init_positions(&game);
	game.xwin = 0;
	game.owin = 0;
	reset(KEYCODE_1, &game);
	//mlx_key_hook(game.w.win, &play_hook, &game);
	mlx_hook(game.w.win, 2, 0, &play_hook, &game);
	mlx_loop(game.w.mlx);
	return (0);
}
