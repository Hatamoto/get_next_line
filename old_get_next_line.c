/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:22 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/21 14:24:28 by mburakow         ###   ########.fr       */
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
	int			chread;

	char			remchktemp[BUFFER_SIZE + 1];
	
	chread = 0;
	i = 0;
	line = NULL;
	// printf("remainder: %s\n", remainder);
	eol = 0;
	if (*remainder != '\0')
	{
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
		line = realloc_line(line);
		if (!line)
			return (NULL);
		chread = read(fd, buf, BUFFER_SIZE);
		buf[chread] = '\0';
		j = 0;
		while (buf[j] != '\0')
		{
			if (!eol)
			{
				line[i++] = buf[j++];
				if (buf[j - 1] == '\n')
				{
					line[i] = '\0';
					eol = 1;
					i = 0;
				}
			}
			else
			{
				remainder[i++] = buf[j++];
				remchktemp[i] = buf[j];
			}
		}
		remainder[j] = '\0';
	}
	return (line);
}
