/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:22 by mburakow          #+#    #+#             */
/*   Updated: 2023/12/01 03:08:28 by mburakow         ###   ########.fr       */
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

static char	*ft_shift_left(char *buffer, int offset)
{
	int	i;

	i = 0;
	while (buffer[i + offset])
	{
		buffer[i] = buffer[i + offset];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*nl_shift_buf(char *buffer, char *line, int nl_index)
{
	char	*temp;	

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
	return (line);
}

char	*read_to_buf(int fd, char *buffer)
{
	int		bts_read;
	char	*line;
	int		nl_index;

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
			return (free(line), NULL);
		if (bts_read == 0)
			ft_memset(buffer, 0, (size_t)BUFFER_SIZE + 1);
		nl_index = ft_strcpos(buffer, '\n');
	}
	if (bts_read > 0 && nl_index > -1)
		return (nl_shift_buf(buffer, line, nl_index));
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
