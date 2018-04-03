/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:45:40 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 13:32:07 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "mlx.h"
# include "structs.h"
# include "libft.h"
# include "defines.h"

void	color_pixel(t_mlx *ptr, int x, int y, int color);
void	draw_segment(t_data *data, t_coo *coo);
void	draw_options(t_mlx *opti);
void	write_options(t_mlx *opti);
void	draw_background(t_mlx *mlx);
int		draw_image(t_data *data);
/*
**	Functions used to draw the image.
*/

#endif
