/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:54:53 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/18 09:15:19 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_temp;
	char	*dest_temp;
	size_t	count;

	src_temp = (char *)src;
	dest_temp = (char *)dest;
	count = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	else if (dest_temp > src_temp)
	{
		while (n-- > 0)
			dest_temp[n] = src_temp[n];
	}
	else
	{
		while (count < n)
		{
			dest_temp[count] = src_temp[count];
			count++;
		}
	}
	return (dest);
}
