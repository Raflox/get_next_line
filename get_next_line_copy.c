/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:04:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/07 15:08:50 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*get_next_line_copy(int fd)
{
	char				buff[BUFFER_SIZE];
	static char			*stack;
	char				*line;

	if (read(fd, buff, BUFFER_SIZE) < 0)
		return (NULL);
	stack = ft_strjoin(stack, buff);
	int idx = 0;
	int len = 0;
	while (idx < BUFFER_SIZE && stack[idx] != '\n' && stack[idx] != EOF)
	{
		len++;
		idx++;
	}
	printf("%d", len);
	idx = 0;
	line = malloc((len + 1) * sizeof(char));
	printf("%s", stack);
	while (stack[idx] != '\n')
	{
		line[idx] = stack[idx];
		idx++;
	}
	line[idx] = '\0';
	
	return (line);
}
 */