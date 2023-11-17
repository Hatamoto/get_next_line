/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburakow <mburakow@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:22 by mburakow          #+#    #+#             */
/*   Updated: 2023/11/17 22:23:08 by mburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		remainder[BUFFER_SIZE]; //char ** to hold remainders? How do I free them if 
							//	main does not read until EOF?
	char 			buf[BUFFER_SIZE];
	char 			*line; // malloc
	int				i;
	int				eol;
	
	i = 0;
	line = NULL;
	while (i < BUFFER_SIZE)
	{
		read(fd, buf, BUFFER_SIZE);
		i++;
	}
	eol = 0;
	i = 0;
	while (remainder[i] != '\0')
	{
		// first alloc needs to be here!
		line[i] = remainder[i];
		remainder[0] = '\0';
	}	
	while (eol == 0)
	{
		while (i < BUFFER_SIZE)
		{
			read(fd, buf, BUFFER_SIZE);
			i++;
		}
		// line += malloc(BUFFER_SIZE);
		i = 0;
		while (buf[i] != '\0')
		{
			while (buf[i] != '\n')
				line[i] = buf[i];
			if (buf[i] == '\n')
			{
				line[i] = buf[i];
				line[i+1] = '\0';
				eol = 1;
				while (buf[i] != '\0')
				{
					remainder* = buf[i];
					remainder++;
					i++;
				}
			}
			i++;
		}
	}
	// If no newline, read again
	



	line = buf_to_line(line, buf);
	/*
	while (found_eol == -1)
	{
		pos += read(fd, buf, 1); 
		found_eol = check_line_end(buf);
		if (found_eol == -1)
			line = buf_to_line(line, buf);
	}
	*/
}
