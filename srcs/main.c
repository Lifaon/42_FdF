/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:07:00 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 16:45:09 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_includes.h"

int		mouse_actions(int key, int x, int y, t_data *data)
{
	if (key == SCROLL_U || key == SCROLL_D)
		zoom(data, key);
	if (key == LCLIC)
		color(data, x, y);
	return (0);
}

int		key_actions(int key, t_data *data)
{
	if (key == RPLUS || key == RLESS)
		zoom(data, key);
	else if (key == KEY_Z || key == KEY_X)
		altitude(data, key);
	else if (key == KEY_D || key == KEY_A || key == KEY_W || key == KEY_S ||
		key == ARROW_R || key == ARROW_L || key == ARROW_U || key == ARROW_D)
		move(data, key);
	else if (key == SPACE)
		reset_origin(data);
	else if (key == KEY_O)
	{
		write_options(data->mlx);
	}
	else if (key == ESC)
	{
		free_data(data);
		exit(0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data *data;

	if (ac != 2)
	{
		ft_putendl("Usage : ./FdF filename");
		return (-1);
	}
	if (!(data = data_init(av[1])))
		return (-1);
	mlx_string_put(data->mlx->mlx, data->mlx->win, WIDTH / 2 - 69, HEIGHT / 2,
		0xFFFFFF, "Press SPACE...");
	mlx_mouse_hook(data->mlx->win, mouse_actions, data);
	mlx_hook(data->mlx->win, 2, 3, key_actions, data);
	mlx_loop(data->mlx->mlx);
	free_data(data);
	return (0);
}
