/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_all_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:56:29 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 14:44:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_are_all_num(char **arr, int size)
{
	while (--size >= 0)
	{
		if (!ft_isnum(arr[size]))
		{
			return (0);
		}
	}
	return (1);
}
