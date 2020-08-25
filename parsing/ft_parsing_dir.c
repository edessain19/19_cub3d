/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evrard <evrard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:30:40 by evrard            #+#    #+#             */
/*   Updated: 2020/08/25 11:55:29 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_e_w(t_data *data)
{
	if (data->parse.dir == 'E')
	{
		data->rec.planex = 0;
		data->rec.planey = 0.66;
		data->rec.dirx = 1;
		data->rec.diry = 0;
	}
	if (data->parse.dir == 'W')
	{
		data->rec.planex = 0;
		data->rec.planey = -0.66;
		data->rec.dirx = -1;
		data->rec.diry = 0;
	}
}

void	init_n_s(t_data *data)
{
	if (data->parse.dir == 'S')
	{
		data->rec.planex = -0.66;
		data->rec.planey = 0;
		data->rec.dirx = 0;
		data->rec.diry = 1;
	}
	if (data->parse.dir == 'N')
	{
		data->rec.planex = 0.66;
		data->rec.planey = 0;
		data->rec.dirx = 0;
		data->rec.diry = -1;
	}
}


int		init_dir(t_data *data)
{
	data->tex.texwidth = 64;
	data->tex.texheight = 64;
//	data->rec.posx = data->parse.pos_ix;
//	data->rec.posy = data->parse.pos_iy;
	init_e_w(data);
	init_n_s(data);
	if (!(data->spr.zbuffer = malloc(sizeof(int *) * data->parse.r1 + 1)))
		return (exit_all(data));
	return (1);
}
