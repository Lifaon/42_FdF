/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:08:52 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/19 15:47:09 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	color_pixel(t_mlx *mlx, int x, int y, int color)
{
	int res;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	res = color % 0x10000 % 0x100;
	mlx->img_str[(y * WIDTH * 4) + (x * 4)] = res;
	color -= res;
	color /= 0x100;
	res = color % 0x100;
	mlx->img_str[(y * WIDTH * 4) + (x * 4) + 1] = res;
	color -= res;
	color /= 0x100;
	mlx->img_str[(y * WIDTH * 4) + (x * 4) + 2] = color;
}
