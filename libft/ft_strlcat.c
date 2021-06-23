/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:55:24 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/20 20:20:50 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	count_dest;
	size_t	count_src;
	size_t	i;
	char	*s;

	s = (char *)src;
	count_src = ft_strlen(s);
	count_dest = ft_strlen(dest);
	if (size > count_dest)
		len = count_dest + count_src;
	else
		return (count_src + size);
	i = 0;
	while (s[i] && (count_dest + 1) < size)
	{
		dest[count_dest] = s[i];
		count_dest++;
		i++;
	}
	dest[count_dest] = '\0';
	return (len);
}
