/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randbot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:07:59 by albaud            #+#    #+#             */
/*   Updated: 2022/08/02 16:36:27 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	randbot(t_board game)
{
	int	pos;

	pos = ft_randint(0, 9);
	while (game.board.map[(int)pos / 3][(int)pos % 3] != 0)
		pos = ft_randint(0, 9);
	return (pos);
}
