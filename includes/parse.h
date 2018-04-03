/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:59:01 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:40:27 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "mlx.h"
# include "structs.h"
# include "defines.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

t_data	*data_init(char *file);
void	*free_data(t_data *data);
int		**arr_init(t_data *data, const char *file);
t_var	*var_init(void);
t_mlx	*t_mlx_init(char *file);
int		img_init(t_mlx *mlx);
void	get_origins(t_data *data);
/*
**	Functions used to initialize the t_data struct.
*/
void	draw_options(t_mlx *opti);

#endif
