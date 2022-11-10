/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:04:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/10 16:13:54 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linelen(char *str)
{
	int	idx;
	int	len;

	idx = 0;
	len = 1;
	while (str[idx++] != '\n')
		len++;
	return (len);
}
static char	*read_line(int fd, char *buff, char *stack)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!stack)
			stack = ft_strdup("");
		temp = stack;
		stack = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(stack, '\n'))
			break ;
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stack;
	char			*line;
	//char			*temp;
	//int				bytes_read;

	// bytes_read = read(fd, buff, BUFFER_SIZE);
	line = read_line(fd, buff, stack);
	return (line);
}

