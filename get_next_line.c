/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:04:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/09 15:59:25 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linelen(char *str)
{
	int	idx;
	int	len;

	idx = 0;
	len = 0;
	while (str[idx++] != '\n')
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stack;
	char			*line;
	char			*temp;
	int				bytes_read;
	
	bytes_read = 1;
	// bytes_read = read(fd, buff, BUFFER_SIZE);
	line = ft_strdup("");
	while (bytes_read)
	{
		if ((bytes_read = read(fd, buff, BUFFER_SIZE)) <= 0)
			return (NULL);
		buff[bytes_read] = '\0';
		if (!stack)
			stack = ft_strdup("");
		temp = ft_strjoin(stack, buff);
		free(stack);
		stack = temp;
		if (ft_strchr(stack, '\n'))
		{
			printf("-%s\n", stack);
			line = ft_substr(stack, 0, ft_linelen(stack));
			break ;
		}
	}
	return (line);
}
