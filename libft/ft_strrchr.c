/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:13:55 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/18 21:19:17 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	last;
	int	len_s;

	count = 0;
	last = -1;
	len_s = ft_strlen(s);
	while (count <= len_s)
	{
		if (*(s + count) == c)
			last = count;
		count++;
	}
	if (last >= 0)
		return ((char *)s + last);
	return (NULL);
}
