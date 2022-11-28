/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:04:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/25 14:15:48 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buff, char *stack)
{
	int		bytes_read;
	char	*temp;

	//free stack??
	bytes_read = 1;
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
	int		count;
	char	*new_stack;
	
	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (NULL);
	//Este -2 não faz sentido aqui
	new_stack = ft_substr(line, count + 1, ft_strlen(line));
	if (*new_stack == '\0')
	{
		free(new_stack);
		new_stack = NULL;
	}
	//printf("count-%d\n", count);
	
	//free new_stack?
	line[count + 1] = '\0';
	return (new_stack);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*stack;
	char			*line;
	//char			*temp;
	//int				bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	// bytes_read = read(fd, buff, BUFFER_SIZE);
	line = read_line(fd, buff, stack);
	free(buff);
	buff = NULL;
	if (!line)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	stack = stack_and_return(line);
	//printf("2-%s\n", stack);
	return (line);
}

