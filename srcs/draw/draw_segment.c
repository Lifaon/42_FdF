/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:02:31 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/20 16:18:02 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	dx(t_data *data, t_coo *coo, t_seg *seg)
{
	int x;
	int y;
	int cumul;
	int i;

	x = coo->xi;
	y = coo->yi;
	cumul = seg->dx / 2;
	i = 1;
	while (i++ <= seg->dx)
	{
		x += seg->xinc;
		cumul += seg->dy;
		if (cumul >= seg->dx)
		{
			cumul -= seg->dx;
			y += seg->yinc;
		}
		color_pixel(data->mlx, x, y, data->var->color);
	}
}

static void	dy(t_data *data, t_coo *coo, t_seg *seg)
{
	int x;
	int y;
	int cumul;
	int i;

	x = coo->xi;
	y = coo->yi;
	cumul = seg->dy / 2;
	i = 1;
	while (i++ <= seg->dy)
	{
		y += seg->yinc;
		cumul += seg->dx;
		if (cumul >= seg->dy)
		{
			cumul -= seg->dy;
			x += seg->xinc;
		}
		color_pixel(data->mlx, x, y, data->var->color);
	}
}

void		draw_segment(t_data *data, t_coo *coo)
{
	t_seg *seg;

	if ((coo->xi >= WIDTH && coo->xf >= WIDTH) || (coo->xi < 0 && coo->xf < 0)
	|| (coo->yi >= HEIGHT && coo->yf >= HEIGHT) || (coo->yi < 0 && coo->yf < 0))
		return ;
	if (!(seg = (t_seg *)malloc(sizeof(t_seg))))
	{
		ft_putendl("malloc(3) error : could not allocate demanded memory.");
		return ;
	}
	seg->dx = ft_abs(coo->xf - coo->xi);
	seg->dy = ft_abs(coo->yf - coo->yi);
	seg->xinc = (coo->xf - coo->xi > 0) ? 1 : -1;
	seg->yinc = (coo->yf - coo->yi > 0) ? 1 : -1;
	color_pixel(data->mlx, coo->xi, coo->yi, data->var->color);
	if (seg->dx > seg->dy)
		dx(data, coo, seg);
	else
		dy(data, coo, seg);
	free(seg);
}
