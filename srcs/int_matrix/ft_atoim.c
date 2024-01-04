/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:49:36 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 18:50:49 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

t_matrix	ft_atoim(char **str, char split)
{
	t_matrix	res;
	int			k;

	res.map = malloc(ft_strtablen(str) * sizeof(int *));
	k = -1;
	while (str[++k])
		res.map[k] = ft_atoia(str[k], split, &res.size.x);
	res.size.y = k;
	return (res);
}
