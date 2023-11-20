/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:02:05 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/20 16:36:59 by mburakow         ###   ########.fr       */
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
/*
char	*init_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
*/
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

/*
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
