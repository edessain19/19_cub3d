/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:30:40 by evrard            #+#    #+#             */
/*   Updated: 2020/06/08 10:48:24 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_e_w(t_data *data)
{
	if (data->parse.dir == 'W')
	{
		data->rec.planeX = 0;
		data->rec.planeY = 0.66;
		data->rec.dirX = 1;
		data->rec.dirY = 0;
	}
	if (data->parse.dir == 'E')
	{
		data->rec.planeX = 0;
		data->rec.planeY = -0.66;
		data->rec.dirX = -1;
		data->rec.dirY = 0;
	}
}

void	init_n_s(t_data *data)
{
	if (data->parse.dir == 'N')
	{
		data->rec.planeX = -0.66;
		data->rec.planeY = 0;
		data->rec.dirX = 0;
		data->rec.dirY = 1;
	}
	if (data->parse.dir == 'S')
	{
		data->rec.planeX = 0.66;
		data->rec.planeY = 0;
		data->rec.dirX = 0;
		data->rec.dirY = -1;
	}
}


int		init_dir(t_data *data)
{
	init_e_w(data);
	init_n_s(data);
	data->dis.texwidth = 64;
	data->dis.texheight = 64;
//	data->rec.sprwidth = 0;
//	data->rec.sprheight = 0;
//	data->rec.movespeed = 0.2;
//	data->rec.rotspeed = 0.06;
//	if (!(m->spr.zbuffer = malloc(sizeof(float *) * m->el.res_x + 1)))
//		return (exit_all(m));
	return (1);
}
