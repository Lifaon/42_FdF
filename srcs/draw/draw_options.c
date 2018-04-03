/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:59:42 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 13:41:41 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	fill_square(t_mlx *mlx, int xi, int yi, int color)
{
	int x;
	int y;

	y = yi;
	while (++y < yi + 20)
	{
		x = xi;
		while (++x < xi + 20)
			color_pixel(mlx, x, y, color);
	}
}

static void	draw_square(t_mlx *mlx, int xi, int yi, int color)
{
	int i;

	i = -1;
	while (++i <= 20)
		color_pixel(mlx, xi + i, yi, 0xFFFFFF);
	i = -1;
	while (++i <= 20)
		color_pixel(mlx, xi + i, yi + 20, 0xFFFFFF);
	i = -1;
	while (++i <= 20)
		color_pixel(mlx, xi, yi + i, 0xFFFFFF);
	i = -1;
	while (++i <= 20)
		color_pixel(mlx, xi + 20, yi + i, 0xFFFFFF);
	fill_square(mlx, xi, yi, color);
}

void		draw_options(t_mlx *mlx)
{
	int i;

	i = OPTI_W - 205;
	draw_square(mlx, i, 180, WHITE);
	draw_square(mlx, i + 35, 180, YELLOW);
	draw_square(mlx, i + 70, 180, ORANGE);
	draw_square(mlx, i + 105, 180, RED);
	draw_square(mlx, i, 215, CYAN);
	draw_square(mlx, i + 35, 215, GREEN);
	draw_square(mlx, i + 70, 215, BLUE);
	draw_square(mlx, i + 105, 215, VIOLET);
}
