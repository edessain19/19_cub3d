/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:48:13 by edessain          #+#    #+#             */
/*   Updated: 2020/03/04 16:46:58 by edessain         ###   ########.fr       */
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
#define screeWidth 640
#define screeHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


*/

typedef struct		display_s
{
	char			*addr;
	int				color_wall;
	int				color_sky;
	int				color_floor;
}					display_t;

typedef struct		mlx_s
{
	void			*mlx_ptr;
	void			*mlx_win;

}					mlx_t;

typedef struct		rec_s
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
}					rec_t;

typedef struct		data_s
{
	rec_t			*rec;
	mlx_t			*mlx;
	display_t		*dis;

}					data_t;


/*
 ** main.c
 */

void				ft_algo(int argc, char **argv);

/*
 ** init_structure
 */

void				ft_init_struct(data_t *data);

/*
 ** ft_position_direction
 */

void	ft_algo(int agrc, char **argv);
void	ft_start_algo(data_t *data);
void	ft_verline(int x, data_t *data);

/*
void				ray_pos_dir(data_t *data, int w, int y);
void				make_step(data_t *data);
void				perf_DDA(data_t *data);
void				projection_wall(int x, data_t *data, int w, int h);
void				wall_color(data_t *data);
void				ft_verline(int x, data_t *data);
*/
#endif

