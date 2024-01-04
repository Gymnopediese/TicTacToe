/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:27:29 by albaud            #+#    #+#             */
/*   Updated: 2022/07/15 12:32:57 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_replacen(char *to_ch, char *to_re, char *re, int ammount)
{
	if (ammount == -1)
	{
		while (ft_contain_subs(to_ch, to_re))
			to_ch = ft_replace(to_ch, to_re, re);
	}
	else
		while (--ammount >= 0)
			to_ch = ft_replace(to_ch, to_re, re);
	return (to_ch);
}
