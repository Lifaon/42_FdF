/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:30:58 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 14:25:54 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_var	*var_init(void)
{
	t_var	*var;

	if (!(var = (t_var *)malloc(sizeof(t_var))))
	{
		ft_putendl("Error : malloc(3) could not allocate demanded memory.");
		return (NULL);
	}
	var->color = VIOLET;
	var->tile_w = TILE_W;
	var->z = TILE_W / Z_COEFF;
	return (var);
}
