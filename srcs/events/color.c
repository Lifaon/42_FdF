/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:35:07 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:38:14 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse.h"

static int	get_color(int x, int y, int i)
{
	if (y >= 180 && y <= 200)
	{
		if (x >= i && x <= i + 20)
			return (WHITE);
		if (x >= i + 35 && x <= i + 55)
			return (YELLOW);
		if (x >= i + 70 && x <= i + 90)
			return (ORANGE);
		if (x >= i + 105 && x <= i + 125)
			return (RED);
	}
	if (y >= 215 && y <= 235)
	{
		if (x >= i && x <= i + 20)
			return (CYAN);
		if (x >= i + 35 && x <= i + 55)
			return (GREEN);
		if (x >= i + 70 && x <= i + 90)
			return (BLUE);
		if (x >= i + 105 && x <= i + 125)
			return (VIOLET);
	}
	return (-1);
}

void		color(t_data *data, int x, int y)
{
	int i;
	int color;

	i = OPTI_W - 205;
	color = get_color(x, y, i);
	if (color != -1)
	{
		mlx_destroy_image(data->mlx->mlx, data->mlx->img);
		img_init(data->mlx);
		data->var->color = color;
		if (draw_image(data))
		{
			free_data(data);
			exit(0);
		}
		write_options(data->mlx);
	}
}
