/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublons_ia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:41:09 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:45:41 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_doublons_ia(int *arr, int size)
{
	int	x;
	int	y;


	x = -1;
	while (++x < size - 1)
	{
		y = x;
		while (++y < size)
		{
			if (arr[x] == arr[y])
				return (1);
		}
	}
	return (0);
}
