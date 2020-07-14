/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:47:22 by evrard            #+#    #+#             */
/*   Updated: 2020/07/14 08:41:02 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculate_draw_start_end(t_data *data)
{
	data->spr.vmovescreen = (int)(94.0 / data->spr.transformy);
	data->spr.sprheight = (int)fabs((float)data->parse.r2 / data->spr.transformy);
	data->spr.drawstarty = -data->spr.sprheight / 2 + data->parse.r2 / 2
		+ data->spr.vmovescreen;
	if (data->spr.drawstarty < 0)
		data->spr.drawstarty = 0;
	data->spr.drawendy = data->spr.sprheight / 2 + data->parse.r2 / 2
		+ data->spr.vmovescreen;
	if (data->spr.drawendy >= data->parse.r2)
		data->spr.drawendy = data->parse.r2 - 1;
	data->spr.sprwidth = (int)fabs((float)data->parse.r2 / data->spr.transformy);
	data->spr.drawstartx = -data->spr.sprwidth / 2 + data->spr.spritescreenx;
	if (data->spr.drawstartx < 0)
		data->spr.drawstartx = 0;
	data->spr.drawendx = data->spr.sprwidth / 2 + data->spr.spritescreenx;
	if (data->spr.drawendx >= data->parse.r2)
		data->spr.drawendx = data->parse.r1 - 1;
}

void	calculate_transform(int i, t_data *data)
{
	data->spr.spritex = data->spr.sprites_x[i] - data->rec.posX;
	data->spr.spritey = data->spr.sprites_y[i] - data->rec.posY;
	data->spr.invdet = 1.0 / (data->rec.planeX * data->rec.dirY
		- data->rec.dirX * data->rec.planeY);
	data->spr.transformx = data->spr.invdet * (data->rec.dirY *
		data->spr.spritex - data->rec.dirX * data->spr.spritey);
	data->spr.transformy = data->spr.invdet * (-data->rec.planeY *
		data->spr.spritex + data->rec.planeX * data->spr.spritey);
	data->spr.spritescreenx = (int)((data->parse.r1 / 2) *
		(1 + data->spr.transformx / data->spr.transformy));
}

void	ft_switch_sprites(t_data *data, int i, int j)
{
	float	tmp_x;
	float	tmp_y;

//	printf("%i\n%i\n", i, j);
//	data->spr.spritedistance = ((data->rec.posX - data->spr.sprites_x[j]) *
//		(data->rec.posX - data->spr.sprites_x[j]) +
//		(data->rec.posY - data->spr.sprites_y[j]) *
//		(data->rec.posY - data->spr.sprites_y[j]));
	tmp_x = data->spr.sprites_x[i];
	tmp_y = data->spr.sprites_y[i];
	data->spr.sprites_x[i] = data->spr.sprites_x[j];
	data->spr.sprites_y[i] = data->spr.sprites_y[j];
	data->spr.sprites_x[j] = tmp_x;
	data->spr.sprites_y[j] = tmp_y;
}

void    ft_sort_sprite(t_data *data)
{
    int     i;
    int     j;

    i = 0;
    while (i < data->spr.nbsprites - 1)
    {
        data->spr.spritedistance = ((data->rec.posX - data->spr.sprites_x[i]) *
            (data->rec.posX - data->spr.sprites_x[i]) +
            (data->rec.posY - data->spr.sprites_y[i]) *
            (data->rec.posY - data->spr.sprites_y[i]));
        j = i + 1;
        while (j < data->spr.nbsprites)
        {
            if (((data->rec.posX - data->spr.sprites_x[j]) * (data->rec.posX -
                data->spr.sprites_x[j]) + (data->rec.posY -
                data->spr.sprites_y[j]) * (data->rec.posY -
                data->spr.sprites_y[j])) > data->spr.spritedistance)
            {
                ft_switch_sprites(data, i, j);
            }
            j++;
        }
        i++;
    }

}

void    sprites_raycasting(t_data *data)
{
    int     i;

    i = 0;
    ft_sort_sprite(data);
    while (i < data->spr.nbsprites)
    {
        calculate_transform(i, data);
		calculate_draw_start_end(data);
		verline_sprites(data);
		i++;
    }
}
