/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:19:56 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:38:09 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse.h"

void	move(t_data *data, int key)
{
	if (key == KEY_D || key == ARROW_R)
		data->var->x0 -= MOVE_COEFF;
	else if (key == KEY_A || key == ARROW_L)
		data->var->x0 += MOVE_COEFF;
	else if (key == KEY_S || key == ARROW_D)
		data->var->y0 -= MOVE_COEFF;
	else
		data->var->y0 += MOVE_COEFF;
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	img_init(data->mlx);
	if (draw_image(data))
	{
		free_data(data);
		exit(0);
	}
	write_options(data->mlx);
}
