/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:17:55 by albaud            #+#    #+#             */
/*   Updated: 2022/07/17 18:57:39 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../sources.h"

int	ft_str_index_of(char *to_count, char target)
{
	int	counter;

	counter = 0;
	while (*to_count)
	{
		if (*to_count == target)
			return (counter);
		to_count += 1;
	}
	return (-1);
}
