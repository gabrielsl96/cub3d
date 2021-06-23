/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 09:55:51 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/16 20:07:02 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	count = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (count < n)
	{
		if (s1_c[count] != s2_c[count])
			return (s1_c[count] - s2_c[count]);
		count++;
	}
	return (0);
}
