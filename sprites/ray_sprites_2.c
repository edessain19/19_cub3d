/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sprites_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 11:52:48 by evrard            #+#    #+#             */
/*   Updated: 2020/07/22 09:51:59 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	write_sprites(t_data *data)
{
	int y;
	int d;

	d = 0;
	y = data->spr.drawstarty;
	while (y < data->spr.drawendy)
	{
		d = (y - data->spr.vmovescreen) * 256 - data->parse.r2 * 128 +
			data->spr.sprheight * 128;
		data->spr.texy = ((d * 64) / data->spr.sprheight) / 256;
		if ((data->spr.color[64 * data->spr.texy + data->spr.texx] & 0x00FFFFFF) != 0)
			data->dis.addr[y * data->parse.r1 + data->spr.stripe] =
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
		if (data->spr.transformy > 0 && data->spr.stripe > 0 && data->spr.stripe <
			data->parse.r1 && data->spr.transformy < data->spr.zbuffer[data->spr.stripe]
				&& data->spr.texx < 64)
		{
			write_sprites(data);
		}
		data->spr.stripe++;
	}
}
