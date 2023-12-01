/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:02:05 by mburakow          #+#    #+#             */
/*   Updated: 2023/12/01 01:46:32 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (s1)
			s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char *buffer, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	i;

	if (!buffer)
		return (NULL);
	slen = ft_strlen((char *)buffer);
	if (start > slen)
		len = 0;
	else if (slen - start < len)
		len = slen - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len] = '\0';
	i = 0;
	while (i < len && start < slen)
	{
		new[i] = buffer[start + i];
		i++;
	}
	return (new);
}

/*
void	*ft_calloc(size_t count, size_t size)
{
	void	*objs;
	size_t	magic_number;

	magic_number = 0 - 1;
	if (count && size && count > (magic_number / size))
		return (NULL);
	objs = malloc(size * count);
	if (objs == NULL)
		return (NULL);
	ft_bzero(objs, size * count);
	return (objs);
}

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

char	*realloc_line(char *line)
{
	char	*newline;
	int		i;

	i = 0;
	newline = NULL;
	if (line == NULL)
	{
		newline = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!newline)
			return (NULL);
		return (newline);
	}
	else
	{
		newline = (char *)malloc((ft_strlen(line) + BUFFER_SIZE + 1)
				* sizeof(char));
		if (!newline)
			return (NULL);
		while (line[i])
		{
			newline[i] = line[i];
			i++;
		}
	}
	free(line);
	return (newline);
}

int	ft_strcpos(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_shift_left(char *buffer, int offset)
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

int	check_line_end(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*buf_to_line(char const *line, char const *buf)
{
	int		i;
	int		j;
	char	*newline;

	newline = (char *)malloc((ft_strlen(line) + ft_strlen(buf)) + 1);
	if (newline == 0)
		return (-2); // some error handling?
	i = 0;
	j = 0;
	while (line[i] != '\0')
		newline[j++] = line[i++];
	i = 0;
	while (buf[i] != '\0')
		newline[j++] = buf[i++];
	newline[j] = '\0';
	return (newline);
}
*/
