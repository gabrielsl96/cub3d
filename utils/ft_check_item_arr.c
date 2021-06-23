/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_item_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:42:21 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/23 19:54:05 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_item_arr(char **arr, char c)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == c)
				num++;
			j++;
		}
		i++;
	}
	return (num);
}
