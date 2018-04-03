/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:09:47 by mlantonn          #+#    #+#             */
/*   Updated: 2018/02/22 18:12:06 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 2560
# define HEIGHT 1400
# define OPTI_W 260
# define OPTI_H 240

# define TILE_W 40
# define ZOOM 20
# define Z_COEFF 2
# define ALT_COEFF 1
# define MOVE_COEFF 30
/*
**	TILE_W should always be a multiple of 10.
**	Z_COEFF should always be a divisor of TILE_W / ZOOM.
*/

# define WHITE 0xC9C9C9
# define YELLOW 0xEFD807
# define ORANGE 0xCC5500
# define RED 0x850606
# define CYAN 0x28B5FE
# define GREEN 0x561B
# define BLUE 0x2FA7
# define VIOLET 0x8A2BE2

#endif
