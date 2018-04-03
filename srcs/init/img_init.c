/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:48:34 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/21 13:58:26 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		img_init(t_mlx *mlx)
{
	int		bpp;
	int		size_line;
	int		endian;

	if (!(mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
	{
		ft_putendl("mlx_new_image() error");
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->mlx);
		return (-1);
	}
	mlx->img_str = mlx_get_data_addr(mlx->img, &bpp, &size_line, &endian);
	return (0);
}
