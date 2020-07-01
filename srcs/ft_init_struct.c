/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:23:04 by edessain          #+#    #+#             */
/*   Updated: 2020/07/01 10:23:52 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		init_raycasting(t_data *data)
{
	data->rec.speed = 0.2;
	data->rec.rotation = 0.2;
	data->rec.posX = 0.0;
	data->rec.posY = 0;
	data->rec.dirX = 0;
	data->rec.dirY = 0;
	data->rec.planeX = 0;
	data->rec.planeY = 0;
	data->rec.oldplaneX = 0;
	data->rec.cameraX = 0;
	data->rec.raydirX = 0;
	data->rec.raydirY = 0;
	data->rec.mapX = 0;
	data->rec.mapY = 0;
	data->rec.sidedistX = 0;
	data->rec.sidedistY = 0;
	data->rec.perpwalldist = 0;
	data->rec.stepX = 0;
	data->rec.stepY = 0;
	data->rec.hit = 0;
	data->rec.side = 0;
	data->rec.lineheight = 0;
	data->rec.drawstart = 0;
	data->rec.drawend = 0;
	data->rec.wallheight = 0;
}

void		init_parse(t_data *data)
{
	data->parse.info = NULL;
	data->parse.map_str = NULL;
	data->parse.map = NULL;
	data->parse.dir = 0;
	data->parse.nb_sprites = 0;
	data->parse.r1 = 0;
	data->parse.r2 = 0;
	data->parse.n_path = 0;
	data->parse.s_path = 0;
	data->parse.w_path = 0;
	data->parse.e_path = 0;
	data->parse.sp_path = 0;
	data->parse.s = 0;
	data->parse.f = -1;
	data->parse.c = -1;
	data->parse.map_h = 0;
	data->parse.map_w = 0;
	data->parse.pos_init_x = 0;
	data->parse.pos_init_y = 0;
//	data->parse.orientation = 0;
}

void		init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = 0;
	data->mlx.mlx_win = 0;
}

void		init_dis(t_data *data)
{
	data->dis.addr = 0;
	data->dis.img = 0;
	data->dis.line_length = 0;
	data->dis.endian = 0;
	data->dis.bits_per_pixel = 0;

}

void 		init_texture(t_data *data)
{
	data->tex.color_n = 0;
	data->tex.color_s = 0;
	data->tex.color_w = 0;
	data->tex.color_e = 0;
	data->tex.texx = 0;
	data->tex.texy = 0;
	data->tex.texwidth = 0;
	data->tex.texheight = 0;
	data->tex.texpos = 0;
	data->tex.texnum = 0;
	data->tex.color = 0;
	data->tex.step = 0;

}

void		ft_init_struct(t_data *data)
{
	init_raycasting(data);
	init_dis(data);
	init_texture(data);
	init_mlx(data);
	init_parse(data);

}
