/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:22 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/18 20:20:37 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		remainder[BUFFER_SIZE]; //char ** to hold remainders? How do I free them if 
	char 			buf[BUFFER_SIZE];
	char 			*line;
	int				i;
	int				j;
	int				eol;
	
	i = 0;
	line = NULL;
	printf("remainder: %s\n", remainder);
	eol = 0;
	if (*remainder)
	{
		line = malloc(ft_strlen(remainder) + BUFFER_SIZE);
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
		line = realloc_line(line, i);
		read(fd, buf, BUFFER_SIZE);
		while (buf[i] != '\0')
		{
			line[i] = buf[i];
			i++;
			if (buf[i] == '\n')
			{
				line[i] = buf[i];
				line[i + 1] = '\0';
				eol = 1;
				j = -1;
				while (buf[i] != '\0')
					remainder[j++] = buf[i++];
			}
		}
	}
	return(line);
}

int	main(void)
{
	int	fd;
	
	fd = open("testfile.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
