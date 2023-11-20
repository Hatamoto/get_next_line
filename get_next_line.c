/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:22 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/20 16:45:14 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1] = "\0";
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			eol;

	// char			remchktemp[BUFFER_SIZE + 1];
	i = 0;
	line = NULL;
	// printf("remainder: %s\n", remainder);
	eol = 0;
	if (*remainder != '\0')
	{
		// If there is remainder from last read, alloc that to string.
		line = malloc(ft_strlen(remainder) + BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		while (remainder[i] != '\0')
		{
			line[i] = remainder[i];
			i++;
		}
		remainder[0] = '\0';
	}
	j = 0;
	while (eol == 0)
	{
		// This SHOULD realloc the line every time there is need for more room...
		line = realloc_line(line);
		if (!line)
			return (NULL);
		read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		j = 0;
		while (buf[j] != '\0')
		{
			if (!eol)
				line[i++] = buf[j++];
			else
			{
				remainder[i++] = buf[j++];
				// remchktemp[i] = buf[j];
			}
			if (buf[j] == '\n')
			{
				line[i] = buf[j];
				line[i + 1] = '\0';
				eol = 1;
				j++;
				i = 0;
			}
		}
		remainder[j] = '\0';
	}
	return (line);
}
