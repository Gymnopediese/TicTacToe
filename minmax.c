/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:22:38 by albaud            #+#    #+#             */
/*   Updated: 2022/08/08 20:50:06 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	his_best_move(t_matrix map, int piece);
int	my_best_move(t_matrix map, int piece);

int	his_best_move(t_matrix map, int piece)
{
	int	i;
	int	mini;
	int	temp;

	if (win(map.map, 3 * piece))
		return (1);
	if (tie(map.map))
		return (0);
	mini = 1;
	i = -1;
	while (++i < 9)
	{
		if (map.map[i / 3][i % 3] == 0)
		{
			map.map[i / 3][i % 3] = -piece;
			temp = my_best_move(map, piece);
			map.map[i / 3][i % 3] = 0;
			if (temp < mini)
				mini = temp;
		}
	}
	return (mini);
}

int	my_best_move(t_matrix map, int piece)
{
	int	i;
	int	max;
	int	temp;

	if (win(map.map, -3 * piece))
		return (-1);
	if (tie(map.map))
		return (0);
	max = -1;
	i = -1;
	while (++i < 9)
	{
		if (map.map[i / 3][i % 3] == 0)
		{
			map.map[i / 3][i % 3] = piece;
			temp = his_best_move(map, piece);
			map.map[i / 3][i % 3] = 0;
			if (temp > max)
				max = temp;
		}
	}
	return (max);
}

int	minmax(t_board board, int piece)
{
	int			i;
	double		bestpath;
	int			max;
	int			res;

	res = 0;
	max = -1;
	i = -1;
	bestpath = 0;
	while (++i < 9)
	{
		if (board.board.map[i / 3][i % 3] == 0)
		{
			board.board.map[i / 3][i % 3] = piece;
			bestpath = his_best_move(board.board, piece);
			board.board.map[i / 3][i % 3] = 0;
			if (max <= bestpath)
			{
				res = i;
				max = bestpath;
			}
		}
	}
	return (res);
}

/*


#include "header.h"

typedef struct s_minmax
{
	double		result;
	int			piece;
}	t_minmax;


void	best_move(int **map, int depth, int piece, t_minmax *min)
{
	int	i;

	if (win(map, -3 * min->piece))
	{
		min->result -= (double)10 / (double)depth;
		return ;
	}
	if (win(map, 3 * min->piece))
	{
		min->result += (double)10 / (double)depth;
		return ;
	}
	i = -1;
	while (++i < 9)
	{
		if (map[i / 3][i % 3] == 0)
		{
			map[i / 3][i % 3] = piece;
			best_move(map, depth + 1, -piece, min);
			map[i / 3][i % 3] = 0;
		}
	}
}

int	minmax(t_board board, int piece)
{
	t_minmax	min;
	int			i;
	double		bestpath;
	int			res;

	res = 0;
	i = -1;
	bestpath = -9999;
	min.piece = piece;
	while (++i < 9)
	{
		if (board.board.map[i / 3][i % 3] == 0)
		{
			min.result = 0;
			board.board.map[i / 3][i % 3] = piece;
			best_move(board.board.map, 1, -piece, &min);
			board.board.map[i / 3][i % 3] = 0;
			if (bestpath < min.result)
			{
				ft_putintm(board.board);
				ft_putdnbr("bestpath", bestpath);
				ft_putdnbr("min.result", min.result);
				ft_putdnbr("board.board.map[i / 3][i % 3]", board.board.map[i / 3][i % 3]);
				res = i;
				bestpath = min.result;
			}
		}
		
	}
	return (res);
}
*/