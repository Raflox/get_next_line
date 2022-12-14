/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafilipe <rafilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:01:36 by rafilipe          #+#    #+#             */
/*   Updated: 2022/11/09 15:49:32 by rafilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) == (ft_strlen(s1) + ft_strlen(s2)))
		str = (ft_strdup(s1));
	else
		str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[(ft_strlen(s1) + ft_strlen(s2))] = '\0';
	while (s2[++j])
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i + j] = s2[j];
	}
	return (str);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*out;

	i = 0;
	len = ft_strlen((char *)str);
	out = (char *)malloc(len * sizeof(char) + 1);
	if (!out)
		return (NULL);
	out[len] = '\0';
	while (str[i] != '\0')
	{
		out[i] = str[i];
		i++;
	}
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (len < ft_strlen((char *)s))
		str = malloc((len + 1) * sizeof(char));
	if (len >= ft_strlen((char *)s))
		str = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}