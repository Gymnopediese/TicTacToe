/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:19:03 by albaud            #+#    #+#             */
/*   Updated: 2022/07/11 15:46:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*restrict	a;
	const char	*restrict	b;
	size_t					loop;

	loop = -1;
	a = dst;
	b = src;
	while (++loop < n)
		a[loop] = b[loop];
	return (dst);
}
