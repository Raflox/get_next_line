/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:04:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/11 02:32:59 by rafilipe         ###   ########.fr       */
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
	//free stack??
	while (bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
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

static char	*stack_and_return(char *line)
{
	int		idx;
	int		count;
	char	*new_stack;
	
	idx = 0;
	count = 0;
	//free new_stack??
	while (line[idx] != '\0' && line[idx - 1] != '\n')
		idx++;
	//Este -2 não faz sentido aqui
	new_stack = ft_substr(line, count, ft_strlen(line));
	//printf("count-%d\n", count);
	//free new_stack?
	line[count + 1] = '\0';
	return (new_stack);
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
	//printf("1-%s\n", line);
	// free?
	stack = stack_and_return(line);
	//printf("2-%s\n", stack);
	return (line);
}

