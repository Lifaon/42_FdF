/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:00:24 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 15:10:14 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*free_data(t_data *data)
{
	int i;

	if (data->var != NULL)
		free(data->var);
	if (data->arr != NULL)
	{
		i = 0;
		while (data->arr[i] != NULL)
			free(data->arr[i++]);
		free(data->arr);
	}
	if (data->mlx != NULL)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		mlx_destroy_image(data->mlx->mlx, data->mlx->img);
		free(data->mlx);
	}
	free(data);
	return (NULL);
}
