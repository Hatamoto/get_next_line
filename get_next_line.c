/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:22 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/22 22:49:01 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_buf(int fd, char *buffer)
{
	int		bts_read;
	char	*line;
	int		nl_index;

	bts_read = 1;
	line = NULL;
	// Stuff in buffer but no newline
	nl_index = ft_strcpos(buffer, '\n');
	while (bts_read > 0 && nl_index == -1)
	{
		line = ft_strjoin(line, buffer);
		bts_read = read(fd, buffer, BUFFER_SIZE);
		if (bts_read == -1)
		{
			free(line);
			return (NULL);
		}
		nl_index = ft_strcpos(buffer, '\n');
	}
	// We encountered a newline
	if (bts_read > 0 && nl_index >= 0)
	{
		line = ft_strjoin(line, ft_substr(buffer, 0, (nl_index + 1)));
		buffer = ft_shift_left(buffer, (nl_index + 1));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1] = "\0";

	line = read_to_buf(fd, buffer);
	if (line == NULL)
		return (NULL);
	return (line);
}
