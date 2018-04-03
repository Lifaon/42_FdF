/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:21:43 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:37:55 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse.h"

void	zoom(t_data *data, int key)
{
	if ((key == RPLUS || key == SCROLL_U) && data->var->tile_w >= 200)
		return ;
	if ((key == RLESS || key == SCROLL_D) && data->var->tile_w <= TILE_W / ZOOM)
		return ;
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	img_init(data->mlx);
	if (key == RPLUS || key == SCROLL_U)
	{
		data->var->tile_w += TILE_W / ZOOM;
		data->var->z = data->var->tile_w / Z_COEFF;
	}
	else
	{
		data->var->tile_w -= TILE_W / ZOOM;
		data->var->z = data->var->tile_w / Z_COEFF;
	}
	get_origins(data);
	if (draw_image(data))
	{
		free_data(data);
		exit(0);
	}
	write_options(data->mlx);
}
