/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:48:05 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 15:13:21 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_data	*data_init(char *file)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
	{
		ft_putendl("malloc(3) error : could not allocate demanded memory.");
		return (NULL);
	}
	data->var = NULL;
	data->arr = NULL;
	data->mlx = NULL;
	if (!(data->var = var_init()))
		return (free_data(data));
	if (!(data->arr = arr_init(data, file)))
		return (free_data(data));
	if (!(data->mlx = t_mlx_init(file)))
		return (free_data(data));
	return (data);
}
