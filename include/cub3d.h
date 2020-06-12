/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:48:13 by edessain          #+#    #+#             */
/*   Updated: 2020/06/12 11:46:19 by evrard           ###   ########.fr       */
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
	char			dir;
	int				nb_sprites;
	int				r1;
	int				r2;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	char 			*sp_path;
	int				s;
	int				f;
	int				c;
	int				map_h;
	int				map_w;
	}					t_parse;

typedef struct		s_display
{
	int				*addr;
	void			*img;
	int				line_length;
	int				endian;
	int				bits_per_pixel;
	void			*color_n;
	void			*color_s;
	void			*color_e;
	void			*color_w;
	int 			texx;
	int 			texy;
	int 			texwidth;
	int 			texheight;
	int 			texpos;
	int 			*color;
	int 			texnum;
	float 			step;
	int				color_sky; // inutile, = info.c
	int				color_floor; //inutile = info.f
}					t_display;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;

}					t_mlx;

typedef struct		s_rec
{
	float			speed;
	float			rotation;
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
	int 			wallheight;
}					t_rec;

typedef struct		s_data
{
	t_rec			rec;
	t_mlx			mlx;
	t_display		dis;
	t_parse			parse;

}					t_data;


/*
** launching algo
*/

int					main(int argc, char **argv);
void				ft_init_struct(t_data *data);


/*
** raycasting
*/

int					ft_keyboard(int keycode, t_data *data);
void				ft_start_algo(t_data *data);
void				*start_raycasting(t_data *data);
void    			calculate_height(t_data *data);
void    			calculate_dist(t_data *data);
void    			perform_dda(t_data *data);
void    			step_and_sidedist(t_data *data);
void    			ray_and_deltadist(int x, t_data *data);
void				ft_verline(int x, t_data *data);



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

void				ft_size_map(t_data *data, char *str);

int					ft_parsing_map(t_data *data);

void 				calculate_colors(t_data *data);
void				calculate_textures(t_data *data);
int					create_images2(t_data *data);
int					create_images1(t_data *data);
int					generate_textures(t_data *data);

int					init_dir(t_data *data);
void				init_n_s(t_data *data);
void				init_e_w(t_data *data);

/*
** ft_position_direction
*/

int					ft_keyboard(int keycode, t_data *data);
void				ft_start_algo(t_data *data);
void				*ft_algo(t_data *data);
void				ft_verline(int x, t_data *data);

/*
** check errors
*/

int     			check_errors(t_data *data);
int     			check_walls(t_data *data);
int					check_around(int i, int j, t_data *data);
int					check_map_characters(t_data *data);
int					return_error_exit(t_data *data);

int					check_borders_lines(t_data *data);
int					check_borders_columns(t_data *data);
int 				check_pos_init(t_data *data);

int 				check_textures(t_data *data);
int	    			check_path(t_data *data, char *str);
int					check_others(t_data *data);


int     			exit_all(t_data *data);

#endif
