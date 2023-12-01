#include "get_next_line.h"
#include <stdio.h>

void	free_safely(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int ft_read_to_buffer(int fd, char **buffer)
{
	ssize_t			bts_read;
	char		raw_line[BUFFER_SIZE + 1];
	char 		*temp;

	bts_read = 1;
	while (bts_read != 0)
	{
		bts_read = read(fd, raw_line, BUFFER_SIZE);
		if (bts_read == -1)
		{
			free_safely(buffer);
			return (-1);
		}
		raw_line[bts_read] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, raw_line);
		if (*buffer == NULL)
		{
			//free_safely(&raw_line);
			free_safely(&temp);
			return (-1);
		}
		free_safely(&temp);
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	return (0);
}

char	*ft_new_line(char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if(!buffer || buffer[i] == '\0')
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
		new_line[i] = '\n';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_new_buffer(char **buffer)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*buffer)[i] != '\0' && (*buffer)[i] != '\n')
		i++;
	if((*buffer)[i] == '\0')
	{
		free_safely(buffer);
		return (NULL);
	}
	temp = *buffer;
	*buffer = ft_substr(*buffer, i + 1, ft_strlen(*buffer + i));
	if (!(*buffer))
	{
		free_safely(&temp);
		return (NULL);
	}
	free_safely(&temp);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	if (ft_read_to_buffer(fd, &buffer) < 0)
		return (NULL);
	line = ft_new_line(buffer);
	if (!line)
	{
		free_safely(&buffer);
		return (NULL);
	}
	buffer = ft_new_buffer(&buffer);
	return (line);
}