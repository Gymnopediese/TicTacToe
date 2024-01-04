/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_lignes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 10:48:49 by albaud            #+#    #+#             */
/*   Updated: 2022/07/03 18:08:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../sources.h"

char	**ft_read_lignes(char *file_name)
{
	char	*file;
	int		lignes_ammount;
	char	**final;
	int		count;
	int		len;

	file = ft_read(file_name);
	lignes_ammount = ft_count(file, '\n') + 1;
	final = malloc(sizeof(*final) * (lignes_ammount + 1));
	count = -1;
	while (++count < lignes_ammount)
	{
		len = ft_strlen_to(file, '\n');
		final[count] = malloc(sizeof(final[count]) * (len + 1));
		len = 0;
		while (*file != '\n' && *file != 0)
		{
			final[count][len] = *file;
			file += 1;
			len++;
		}
		final[count][len] = 0;
		file += 1;
	}
	final[count] = 0;
	return (final);
}
