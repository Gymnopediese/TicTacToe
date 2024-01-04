/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iatoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:50:00 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 18:51:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_iatoa(int *arr, int size)
{
	char	*res;
	int		k;

	res = malloc(1);
	k = -1;
	while (++k < size)
	{
		res = ft_strjoin(res, ft_itoa(arr[k]));
		if (k < size - 1)
			res = ft_strjoin(res, " ");
	}
	return (res);
}
