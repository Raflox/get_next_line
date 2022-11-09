/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:04:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/08 16:45:38 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* 
char	*get_next_line_copy(int fd)
{
	char				buff[BUFFER_SIZE + 1];
	static char			*stack;
	char				*line;
	char				*temp;
	int					ret;
	
	if ((ret = read(fd, buff, BUFFER_SIZE)) <= 0)
		return (NULL);
	buff[ret] = '\0';
	stack = ft_strdup("");
	temp = ft_strjoin(stack, buff);
	free(stack);
	stack = temp;
	
	int idx = 0;
	int len = 0;
	while (idx < BUFFER_SIZE && stack[idx] != '\n' && stack[idx] != EOF)
	{
		len++;
		idx++;
	}
	printf("%d\n", len);
	idx = 0;
	line = ft_substr(stack, 0, len);
	// line = malloc((len + 1) * sizeof(char));
	// printf("%s\n", stack);
	// while (stack[idx] != '\n')
	// {
	// 	line[idx] = stack[idx];
	// 	idx++;
	// }
	// line[idx] = '\0';
	
	return (line);
}
 */