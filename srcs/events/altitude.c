/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:03:43 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:38:23 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse.h"

void	altitude(t_data *data, int key)
{
	if ((key == KEY_Z && data->var->z >= 100) ||
		(key == KEY_X && data->var->z <= ALT_COEFF))
		return ;
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	img_init(data->mlx);
	if (key == KEY_Z)
		data->var->z += ALT_COEFF;
	else
		data->var->z -= ALT_COEFF;
	if (draw_image(data))
	{
		free_data(data);
		exit(0);
	}
	write_options(data->mlx);
}
