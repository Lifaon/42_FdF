/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:52:48 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:38:06 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse.h"

void	reset_origin(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	img_init(data->mlx);
	get_origins(data);
	if (draw_image(data))
	{
		free_data(data);
		exit(0);
	}
	write_options(data->mlx);
}
