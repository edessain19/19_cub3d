/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:23:04 by edessain          #+#    #+#             */
/*   Updated: 2020/07/20 09:31:46 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		init_raycasting(t_data *data)
{
	data->rec.speed = 0.2;
	data->rec.rotation = 0.2;
	data->rec.posx = 0.0;
	data->rec.posy = 0;
	data->rec.dirx = 0;
	data->rec.diry = 0;
	data->rec.planex = 0;
	data->rec.planey = 0;
	data->rec.oldplanex = 0;
	data->rec.camerax = 0;
	data->rec.raydirx = 0;
	data->rec.raydiry = 0;
	data->rec.mapx = 0;
	data->rec.mapy = 0;
	data->rec.sidedistx = 0;
	data->rec.sidedisty = 0;
	data->rec.perpwalldist = 0;
	data->rec.stepx = 0;
	data->rec.stepy = 0;
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
	data->parse.r1 = 0;
	data->parse.r2 = 0;
	data->parse.n_path = 0;
	data->parse.s_path = 0;
	data->parse.w_path = 0;
	data->parse.e_path = 0;
	data->parse.sp_path = 0;
	data->parse.s = 0;
	data->parse.f = -1;
	data->parse.f1 = 0;
	data->parse.f2 = 0;
	data->parse.f3 = 0;
	data->parse.c = -1;
	data->parse.c1 = 0;
	data->parse.c2 = 0;
	data->parse.c3 = 0;
	data->parse.map_h = 0;
	data->parse.map_w = 0;
	data->parse.pos_ix = 0;
	data->parse.pos_iy = 0;
}

void 		init_check(t_data *data)
{
	data->check.v_r = -1;
	data->check.v_path_n = -1;
	data->check.v_path_s = -1;
	data->check.v_path_e = -1;
	data->check.v_path_w = -1;
	data->check.v_path_sp = -1;
	data->check.v_c = -1;
	data->check.v_f = -1;
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

void 		init_sprites(t_data *data)
{
	data->spr.nbsprites = 0;
	data->spr.spr_tex = NULL;
	data->spr.color = 0;
	data->spr.sprwidth = 0;
	data->spr.sprheight = 0;
	data->spr.spritex = 0;
	data->spr.spritey = 0;
	data->spr.invdet = 0;
	data->spr.transformx = 0;
	data->spr.transformy = 0;
	data->spr.spritescreenx = 0;
	data->spr.drawstarty = 0;
	data->spr.drawendy = 0;
	data->spr.drawstartx = 0;
	data->spr.drawendx = 0;
	data->spr.stripe = 0;
	data->spr.texx = 0;
	data->spr.texy = 0;
	data->spr.zbuffer = 0;
	data->spr.sprites_x = 0;
	data->spr.sprites_y = 0;
	data->spr.spritedistance = 0;
	data->spr.vmovescreen = 0;
}

void		ft_init_struct(t_data *data)
{
	init_raycasting(data);
	init_dis(data);
	init_texture(data);
	init_mlx(data);
	init_parse(data);
	init_sprites(data);
	init_check(data);
}
