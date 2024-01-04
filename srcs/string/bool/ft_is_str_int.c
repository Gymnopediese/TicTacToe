/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:02:33 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:57:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_isstrint(char *str)
{
	if (ft_isnum(str) && ft_atoli(str) >= -2147483648
		&& ft_atoli(str) <= 2147483647)
	{
		return (1);
	}
	return (0);
}
