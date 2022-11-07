/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:04:51 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/07 01:02:18 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			temp[BUFFER_SIZE];
	char			*str;
	int				len;
	static int		idx;
	int				i;
	
	read(fd, temp, BUFFER_SIZE);
	len = ft_strlen(temp);
	printf("%d\n", len);
	idx = 0;
	len = 0;
	while (temp && temp[idx] != '\n' && len < BUFFER_SIZE)
	{
		idx++;
		len++;
	}
	printf("%d\n", len);
	str = calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = temp[i];
		i++;
	}
	return (str);
}
