/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:44:16 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:41:07 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "structs.h"
# include "libft.h"
# include "defines.h"
# include "key_includes.h"

t_data	*data_init(char *file);
void	*free_data(t_data *data);

int		draw_image(t_data *data);
void	write_options(t_mlx *opti);

void	altitude(t_data *data, int key);
void	color(t_data *data, int x, int y);
void	move(t_data *data, int key);
void	zoom(t_data *data, int key);
void	reset_origin(t_data *data);

/*
**	Functions used in the main() function.
*/

#endif
