/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:41:55 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 21:13:53 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbmwords(char const *s1, char c)
{
	int	count;
	int	check;
	int	i;

	count = 0;
	check = 0;
	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
			check = 0;
		else if (check == 0)
		{
			check = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_lenword(char const *s2, char c2, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c2 && s2[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**ft_freearr(char const **dest, int j1)
{
	while (j1 > 0)
	{
		j1--;
		free((void *)dest[j1]);
	}
	free(dest);
	return (NULL);
}

static char	**ft_strwrite(char const *s, char **dest, char c, int words)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dest[j] = malloc(sizeof(char) * ft_lenword(s, c, i) + 1);
		if (!dest)
			return (ft_freearr((char const **)dest, j));
		while (s[i] && s[i] != c)
			dest[j][k++] = s[i++];
		dest[j][k] = '\0';
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = ft_nbmwords(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	return (ft_strwrite(s, str, c, words));
}
