/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:23:04 by edessain          #+#    #+#             */
/*   Updated: 2020/08/31 17:31:58 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void		init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = 0;
	data->mlx.mlx_win = 0;
}

void		init_texture(t_data *data)
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

void		init_sprites(t_data *data)
{
	data->spr.nbsprites = 0;
	data->spr.spr_tex = NULL;
	data->spr.color = 0;
	data->spr.sprwidth = 0;
	data->spr.sprheight = 0;
	data->spr.spritex = 0;
	data->spr.spritey = 0;
	data->spr.invdet = 1;
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
