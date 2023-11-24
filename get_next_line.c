/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:22 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/24 18:06:30 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mem;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	mem = (unsigned char *)b;
	while (i < len)
	{
		mem[i] = d;
		i++;
	}
	return (b);
}

char	*read_to_buf(int fd, char *buffer)
{
	int		bts_read;
	char	*line;
	int		nl_index;
	char	*temp;

	bts_read = 1;
	line = NULL;
	nl_index = ft_strcpos(buffer, '\n');
	while (bts_read > 0 && nl_index == -1)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
		bts_read = read(fd, buffer, BUFFER_SIZE);
		if (bts_read == -1)
		{
			free(line);
			ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
			return (NULL);
		}
		if (bts_read == 0)
			ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
		nl_index = ft_strcpos(buffer, '\n');
	}
	if (bts_read > 0 && nl_index > -1)
	{
		temp = ft_substr(buffer, 0, (nl_index + 1));
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, temp);
		free (temp);
		if (line == NULL)
		{
			ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
			return (NULL);
		}
		buffer = ft_shift_left(buffer, (nl_index + 1));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
		return (NULL);
	}
	line = read_to_buf(fd, buffer);
	if (line == NULL)
	{
		ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
		return (NULL);
	}
	if (*line == '\0')
	{
		ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
		free (line);
		return (NULL);
	}
	return (line);
}
