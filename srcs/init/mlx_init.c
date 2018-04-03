/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:45:20 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/21 13:58:21 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_mlx	*t_mlx_init(char *file)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		ft_putendl("malloc(3) error : could not allocate demanded memory.");
		return (NULL);
	}
	if (!(mlx->mlx = mlx_init()))
	{
		ft_putendl("mlx_init() error.");
		return (NULL);
	}
	if (!(mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, file)))
	{
		ft_putendl("mlx_new_window() error.");
		free(mlx->mlx);
		return (NULL);
	}
	if (img_init(mlx))
		return (NULL);
	return (mlx);
}
