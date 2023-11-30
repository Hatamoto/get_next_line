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
#include <stdio.h>

char	*ft_read_to_buffer(int fd, char *buffer)
{
	int			bts_read;
	char		*raw_line;
	
	raw_line = (char *)malloc((sizeof(char) * BUFFER_SIZE + 1));
	if (!raw_line)
		return (NULL);
	bts_read = 1;
	while (bts_read > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		bts_read = read(fd, raw_line, BUFFER_SIZE);
		if (bts_read == -1)
		{
			free(raw_line);
			free(buffer);
			return (NULL);
		}
		raw_line[bts_read] = '\0';
		buffer = ft_strjoin(buffer, raw_line);
	}
	free(raw_line);
	return (buffer);
}

char	*ft_new_line(char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if(!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		new_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		new_line[i] = buffer[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_new_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if(buffer[i] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i] != '\0')
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free (buffer);
	return (new_buffer); 
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	// Because this can happen after the first call
	if (read(fd, 0 ,0) < 0)
	{
		if (buffer)
			free (buffer);
			// ft_memset(buffer, 0, ft_strlen(buffer));
		return (NULL);
	}
	buffer = ft_read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_new_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (line);
}