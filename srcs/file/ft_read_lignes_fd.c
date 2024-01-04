/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_lignes_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:50:12 by albaud            #+#    #+#             */
/*   Updated: 2022/07/14 18:05:13 by albaud           ###   ########.fr       */
/*                                                                            */
/*   Name: ft_read_lignes_fd - read text from an open fd line by line         */
/*                                                                            */
/*   Categorie: file reading                                                  */
/*                                                                            */
/*   Synopsis: #include <unistd.h>,                                           */
/*             #include <stdlib.h>,                                           */
/*                                                                            */
/*             char	**ft_read_lignes_fd(int fd)                               */
/*                                                                            */
/*   Depend on: read(),                                                       */
/*              malloc()                                                      */
/*                                                                            */
/*   Description: ft_read_lignes_fd() attempt to read an open file line by    */
/*                line using its fd and return a table of string.             */
/*                                                                            */
/*   Return value: Return a table of string. If an error occurs, it return    */
/*                 NULL.                                                      */
/*                                                                            */
/*   Errors: Don't run this code on a Gameboy please.                         */
/*                                                                            */
/*   See also: ft_read_lignes(), ft_read(), ft_read_fd()                      */
/*                                                                            */
/*   History: I needed it for the get_next_line() function. My final          */
/*            get_next_line() function is the worst piece of code ever        */
/*            made but it has all the bonuses so...                           */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	**ft_read_lignes_fd(int fd)
{
	char	*file;
	int		lignes_ammount;
	char	**final;
	int		count;
	int		len;

	file = ft_read_fd(fd);
	if (!file[0])
		return (0);
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
