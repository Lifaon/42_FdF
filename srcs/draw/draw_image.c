/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:17:20 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:38:52 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_image2(t_data *data, t_coo *coo, int y)
{
	int x;

	x = 0;
	while (x < data->var->xmax)
	{
		if (data->arr[y + 1] != NULL)
		{
			coo->yf = coo->yi + (data->var->tile_w / 2) -
				((data->arr[y + 1][x] - data->arr[y][x]) * data->var->z);
			coo->xf = coo->xi - data->var->tile_w;
			draw_segment(data, coo);
		}
		if (x + 1 < data->var->xmax)
		{
			coo->yf = coo->yi + (data->var->tile_w / 2) -
				((data->arr[y][x + 1] - data->arr[y][x]) * data->var->z);
			coo->xf = coo->xi + data->var->tile_w;
			draw_segment(data, coo);
		}
		coo->yi = coo->yf;
		coo->xi = coo->xf;
		++x;
	}
}

int			draw_image(t_data *data)
{
	t_coo	*coo;
	int		y;

	if (!(coo = (t_coo *)malloc(sizeof(t_coo))))
	{
		ft_putendl("malloc(3) error : could not allocate demanded memory.");
		return (-1);
	}
	coo->yi = data->var->y0 - (data->arr[0][0] * data->var->z);
	coo->xi = data->var->x0;
	y = 0;
	while (data->arr[y] != NULL)
	{
		draw_image2(data, coo, y);
		if (data->arr[++y] == NULL)
			break ;
		coo->yi = data->var->y0 + (y * data->var->tile_w / 2) -
			(data->arr[y][0] * data->var->z);
		coo->xi = data->var->x0 - (y * data->var->tile_w);
	}
	free(coo);
	draw_options(data->mlx);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img,
		0, 0);
	return (0);
}
