/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:48:13 by edessain          #+#    #+#             */
/*   Updated: 2020/03/11 13:11:58 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"

/*
** definition structure
*/

typedef struct		s_parse
{
	char			*info;
	char			*map_str;
	char			**map;
}					t_parse;

typedef struct		s_info_map
{
	int				r1;
	int				r2;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f1;
	int				f2;
	int				f3;
	int				c;
}					t_info_map;

typedef struct		s_display
{
	int				*addr;
	void			*img;
	int				line_length;
	int				endian;
	int				bits_per_pixel;
	int				color_wall_n;
	int				color_wall_s;
	int				color_wall_e;
	int				color_wall_w;
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
	double			olddirX;
	double			olddirY;
	double			planeX;//plan de la camera
	double			planeY;//plan de la camera
	double			oldplaneX;
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
}					t_rec;

typedef struct		s_data
{
	t_rec			rec;
	t_mlx			mlx;
	t_display		dis;
	t_parse			parse;
	t_info_map		info;

}					t_data;

/*
** init_struct
*/

void				ft_init_struct(t_data *data);

/*
** parsing
*/

int					ft_parse_cub(t_data *data, char *filename);
int					parse_map(int fd, t_data *data);
int					parse_info(int fd, t_data *data);

int					ft_strlen_parsing(char *str, int i, char c);
int					ft_get_texture(char *str, int i, t_data *data, char c);
int					ft_get_size(char *str, int i, t_data *data, char c);
int					ft_parsing_lettre(char *str, int i, t_data *data, char c);
int					ft_parsing_info(t_data *data);


/*
** ft_position_direction
*/

int		ft_keyboard(int keycode, t_data *data);
void	ft_start_algo(t_data *data);
void	*ft_algo(t_data *data);
void	ft_verline(int x, t_data *data);

#endif

