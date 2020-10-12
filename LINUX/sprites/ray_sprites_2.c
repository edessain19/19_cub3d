/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sprites_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:52:48 by evrard            #+#    #+#             */
/*   Updated: 2020/09/15 16:52:39 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	write_sprites(t_data *data)
{
	int		y;
	int		d;

	d = 0;
	y = data->spr.drawstarty;
	while (y < data->spr.drawendy)
	{
		d = y * 256 - data->parse.screen_y * 128 +
			data->spr.sprheight * 128;
		data->spr.texy = ((d * 64) / data->spr.sprheight) / 256;
		if (data->spr.texy < 64 && ((data->spr.color[64 * data->spr.texy
		+ data->spr.texx] & 0x00FFFFFF) != 0))
			data->dis.addr[y * data->parse.screen_x + data->spr.stripe] =
				data->spr.color[64 * data->spr.texy + data->spr.texx];
		y++;
	}
}

void	verline_sprites(t_data *data)
{
	data->spr.stripe = data->spr.drawstartx;
	while (data->spr.stripe < data->spr.drawendx)
	{
		data->spr.texx = (int)((data->spr.stripe - (-data->spr.sprwidth / 2
		+ data->spr.spritescreenx)) * 64 / data->spr.sprwidth);
		if (data->spr.transformy > 0 && data->spr.stripe > 0
			&& data->spr.stripe < data->parse.screen_x && data->spr.transformy
			< data->spr.zbuffer[data->spr.stripe]
			&& data->spr.texx < 64)
		{
			write_sprites(data);
		}
		data->spr.stripe++;
	}
}

void	calculate_draw_start_end(t_data *data)
{
	data->spr.sprheight = (int)fabs((float)data->parse.screen_y /
		data->spr.transformy);
	data->spr.drawstarty = -data->spr.sprheight / 2 + data->parse.screen_y / 2;
	if (data->spr.drawstarty < 0)
		data->spr.drawstarty = 0;
	data->spr.drawendy = data->spr.sprheight / 2 + data->parse.screen_y / 2;
	if (data->spr.drawendy >= data->parse.screen_y)
		data->spr.drawendy = data->parse.screen_y - 1;
	data->spr.sprwidth = (int)fabs((float)data->parse.screen_y
		/ data->spr.transformy);
	data->spr.drawstartx = -data->spr.sprwidth / 2 + data->spr.spritescreenx;
	if (data->spr.drawstartx < 0)
		data->spr.drawstartx = 0;
	data->spr.drawendx = data->spr.sprwidth / 2 + data->spr.spritescreenx;
	if (data->spr.drawendx >= data->parse.screen_x)
		data->spr.drawendx = data->parse.screen_x - 1;
}

void	calculate_transform(int i, t_data *data)
{
	data->spr.spritex = data->spr.sprites_x[i] - data->rec.posx;
	data->spr.spritey = data->spr.sprites_y[i] - data->rec.posy;
	data->spr.invdet = 1.0 / (data->rec.planex * data->rec.diry
		- data->rec.dirx * data->rec.planey);
	data->spr.transformx = data->spr.invdet * (data->rec.diry *
		data->spr.spritex - data->rec.dirx * data->spr.spritey);
	data->spr.transformy = data->spr.invdet * (-data->rec.planey *
		data->spr.spritex + data->rec.planex * data->spr.spritey);
	data->spr.spritescreenx = (int)((data->parse.screen_x / 2) *
		(1 + data->spr.transformx / data->spr.transformy));
}
