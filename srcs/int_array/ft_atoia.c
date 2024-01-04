/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:50:32 by albaud            #+#    #+#             */
/*   Updated: 2022/07/20 20:42:43 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

int	*ft_atoia(char *str, char split, double *size)
{
	char	**buffer;
	int		*res;
	int		k;

	buffer = ft_strsplit(str, split);
	res = malloc(ft_strtablen(buffer) * sizeof(int));
	k = -1;
	while (buffer[++k])
		res[k] = ft_atoli(buffer[k]);
	*size = k;
	ft_free_pp((void *)buffer);
	return (res);
}
