/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:48:13 by edessain          #+#    #+#             */
/*   Updated: 2020/02/27 15:08:55 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../X11/includes/mlx.h"

typedef struct		data_s
{
	void			*mlx_ptr;
	void			*mlx_win;

}					data_t;

typedef struct		position_s
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
}					position_t;

void				ft_algo(int argc, char **argv);

#endif

