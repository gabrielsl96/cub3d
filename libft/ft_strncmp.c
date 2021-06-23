/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:33:07 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/18 09:14:51 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	count = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (count < n && (s1_c[count] != '\0' || s2_c[count] != '\0'))
	{
		if (s1_c[count] != s2_c[count])
		{
			return (s1_c[count] - s2_c[count]);
		}
		count++;
	}
	return (0);
}
