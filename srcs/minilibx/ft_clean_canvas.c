/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:08:57 by albaud            #+#    #+#             */
/*   Updated: 2022/07/24 12:05:24 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	ft_clean_canvas(t_canvas cvs)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cvs.x)
	{
		j = -1;
		while (++j < cvs.y)
			ft_put_pixel(&cvs, i, j, 0);
	}
}
