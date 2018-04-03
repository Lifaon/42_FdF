/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:55:38 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 13:14:10 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_var
{
	int				color;
	int				tile_w;
	int				z;
	int				xmax;
	int				x0;
	int				y0;
}					t_var;
/*
**	Struct used to store the variables to modify the image.
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
}					t_mlx;
/*
**	Struct used to store the necessary pointers for the mlx usage.
*/

typedef struct		s_coo
{
	int				xi;
	int				yi;
	int				xf;
	int				yf;
}					t_coo;
/*
**	Struct used for the draw_image() function.
*/

typedef struct		s_seg
{
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
}					t_seg;
/*
**	Struct used for the draw_segment() function.
*/

typedef struct		s_data
{
	int				**arr;
	t_var			*var;
	t_mlx			*mlx;
}					t_data;
/*
**	Struct used to store different pointers.
*/

#endif
