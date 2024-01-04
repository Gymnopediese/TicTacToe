/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:32:43 by albaud            #+#    #+#             */
/*   Updated: 2022/07/11 15:50:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	char		*restrict	a;
	const char	*restrict	b;
	size_t					loop;

	loop = -1;
	a = dst;
	b = src;
	while (++loop < n)
	{
		if ((unsigned char) b[loop] == (unsigned char) c)
		{
			a[loop] = 0;
			return (&dst[loop + 1]);
		}
		a[loop] = b[loop];
	}
	return (0);
}
