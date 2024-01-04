/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstra_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:48:59 by albaud            #+#    #+#             */
/*   Updated: 2022/07/18 18:32:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_putstra_join(char **arr, char *glue, int endl)
{
	int		i;

	i = -1;
	if (arr == 0)
		return ;
	while (arr[++i])
	{
		ft_putstr(arr[i]);
		if (arr[i + 1])
			ft_putstr(glue);
	}
	if (endl)
		ft_putstr("\n");
}
