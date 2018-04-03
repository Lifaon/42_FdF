/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_origins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:04:01 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/20 17:03:23 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_origins(t_data *data)
{
	int		ymax;

	ymax = 0;
	while (data->arr[ymax] != NULL)
		++ymax;
	data->var->y0 = HEIGHT / 2 - ((data->var->xmax + ymax - 2) *
		data->var->tile_w / 4);
	data->var->x0 = WIDTH / 2 - ((data->var->xmax - ymax) *
		data->var->tile_w / 2);
}
