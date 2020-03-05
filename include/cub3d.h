/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:48:13 by edessain          #+#    #+#             */
/*   Updated: 2020/03/05 13:52:47 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../minilibx/mlx.h"

/*
** definition structure
*/

typedef struct		s_display
{
	int				*addr;
	void			*img;
	int				line_length;
	int				endian;
	int				bits_per_pixel;
	int				color_wall1;
	int				color_wall2;
	int				color_sky;
	int				color_floor;
}					t_display;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;

}					t_mlx;

typedef struct		s_rec
{
	double			posX;//position initiale
	double			posY;//position initiale
	double			dirX;//direction initiale
	double			dirY;//direction initiale
	double			planeX;//plan de la camera
	double			planeY;//plan de la camera
	double			time;
	double			oldtime;
	double			cameraX;//coordonee x sur le plan de la camera
	double			raydirX;//direction du mouvement
	double			raydirY;//diection du mouvement
	int				mapX;
	int				mapY;
	double			sidedistX;
	double			sidedistY;
	double			deltadistX;//distance sur l'axe des x
	double			deltadistY;//distance sur l'ace des y
	double			perpwalldist;
	int				stepX;//what direction to step in x or y-direction (+1 or -1)
	int				stepY;
	int				hit;
	int				side;//was a NS or a EW wall hit?
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			olddirX;
	double			oldplaneX;
	int				color;
}					t_rec;

typedef struct		s_data
{
	t_rec			rec;
	t_mlx			mlx;
	t_display		dis;

}					t_data;

/*
** init_struct
*/

void				ft_init_struct(t_data *data);

/*
** ft_position_direction
*/

void	ft_algo(t_data *data);
void	*ft_start_algo(t_data *data);
void	ft_verline(int x, t_data *data);

#endif

