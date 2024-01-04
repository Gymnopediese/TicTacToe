/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:58:37 by albaud            #+#    #+#             */
/*   Updated: 2022/07/19 17:25:16 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources.h"

char	*ft_read(char *file_name)
{
	int		size;
	char	*buffer;
	int		fd;
	char	tuffer[3333];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(1);
	size = read(fd, tuffer, 3333);
	while (size)
	{
		buffer = ft_strjoin(buffer, tuffer);
		size = read(fd, tuffer, 3333);
	}
	close(fd);
	return (buffer);
}
