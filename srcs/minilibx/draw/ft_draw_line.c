/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:31:27 by albaud            #+#    #+#             */
/*   Updated: 2022/07/22 19:58:55 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

void	ft_draw_line(t_canvas *cvs, t_vector a, t_vector b, int color)
{
	t_vector	toadd;

	toadd.y = -ft_bound(fabs(a.y - b.y) / fabs(a.x - b.x), 0, 1);
	toadd.x = -ft_bound(fabs(a.x - b.x) / fabs(a.y - b.y), 0, 1);
	if (a.x - b.x < 0)
		toadd.x *= -1;
	if (a.y - b.y < 0)
		toadd.y *= -1;
	while (!ft_vector_eql(ft_vector_int(a), b))
	{
		ft_put_pixel(cvs, round(a.x), round(a.y), color);
		a = ft_add_to_vector(a, toadd.x, toadd.y, 0);
	}
}
