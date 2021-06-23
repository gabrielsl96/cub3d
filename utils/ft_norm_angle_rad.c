/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_angle_rad.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:12:06 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/06/21 22:14:33 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	ft_norm_angle_rad(double angle_rad)
{
	double	angle_norm;

	angle_norm = angle_rad;
	if (angle_norm > NUM_PI)
		angle_norm -= (2 * NUM_PI);
	if (angle_norm < -NUM_PI)
		angle_norm += (2 * NUM_PI);
	return (angle_norm);
}
