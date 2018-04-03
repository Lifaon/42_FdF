/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:21:30 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:32:55 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	write_options(t_mlx *opti)
{
	mlx_string_put(opti->mlx, opti->win, 25, 20, 0xFFFFFF,
		"move : arrows or WASD");
	mlx_string_put(opti->mlx, opti->win, 25, 50, 0xFFFFFF,
		"zoom : scroll or + / -");
	mlx_string_put(opti->mlx, opti->win, 25, 80, 0xFFFFFF,
		"altitude : Z / X");
	mlx_string_put(opti->mlx, opti->win, 25, 110, 0xFFFFFF,
		"reset pos : SPACE");
	mlx_string_put(opti->mlx, opti->win, 25, 140, 0xFFFFFF,
		"colors (clic on one)");
}
