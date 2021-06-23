/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 23:14:43 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 21:09:39 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*((char *)s + count) != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;

	if (s1 && s2)
	{
		new = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (new)
		{
			i = 0;
			while (*s1 != '\0')
				new[i++] = *s1++;
			while (*s2 != '\0')
				new[i++] = *s2++;
			new[i++] = '\0';
			return (new);
		}
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;
	int	len_s;

	count = 0;
	len_s = ft_strlen(s);
	while (count <= len_s)
	{
		if (*(s + count) == c)
			return (((char *)s + count));
		count++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	if (start < len_s)
	{
		j = start;
		while (j < len + start && s[j] != '\0')
		{
			sub[i] = s[j];
			i++;
			j++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		count;
	char	*dest;

	count = 0;
	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (count < len)
	{
		dest[count] = s[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
