/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:39:47 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 21:20:36 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
